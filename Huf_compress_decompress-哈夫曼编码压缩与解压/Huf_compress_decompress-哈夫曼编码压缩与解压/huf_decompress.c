#define _CRT_SECURE_NO_WARNINGS 1

#include "huf_decompress.h"

//	确认密码
static Status ConfirmPwd(unsigned int pwd1,unsigned int pwd2)
{
	if(pwd1 == pwd2)
		return OK;
	else
		return WRONGPWD;
}
//	确认标识
static Status ConfirmMark(char* mark1,char* mark2)
{
	if( strcmp(mark1,mark2) == 0)
		return OK;
	else
		return WRONGMARK;
}
//	创建解压文件
static Status ReadCompressFile(FILE* pfIn,FreqList FL,char* destfile)
{
	FILE* pfOut = fopen(destfile,"wb");
	int root = 0;	//	记录字符频率表根结点下标
	int index = 0;	//	用于记录下标
	int filelength = get_file_size(pfIn) - ftell(pfIn);
	
	while(1)
	{
		if(FL[root].parent == -1)
			break;
		++root;
	}

	index = root;
	while(1)
	{
		unsigned char ch = 0;	//	临时存放字符变量
		
		int j = 0;	//	范围：1-8	用于位操作

		if(!filelength)
			break;
		filelength--;

		ch = fgetc(pfIn);
		if(ferror(pfIn))
			return UNKNOW;

		while(j != 8)
		{
			if( (ch & (1<<(7-j))) == 0)	//	左0右1
				index = FL[index].lch;
			else
				index = FL[index].rch;
			if(FL[index].lch == -1)	//	哈夫曼树的结点的度数为0或2，没有度为1的结点。
			{
				if(1 != fwrite(&(FL[index].cInfo.c),sizeof(FL[index].cInfo.c),1,pfOut))
					return UNKNOW;
				index = root;
			}
			++j;
		}
	}


	fclose(pfOut);
	pfOut=NULL;
	return OK;
}

//	哈夫曼编码解压
static Status HufDecompress(char srcfile[FILENAMEMAXSIZE],unsigned int pwd)
{
	FreqList FL = NULL;
	FILE* pfIn = NULL;
	FileHead fh;
	Status ret = OK;
	char* mark = NULL;

	pfIn = fopen(srcfile,"rb");
	if(pfIn == NULL)
	{
		ConfirmError(NOFOUND);
		return NOFOUND;
	}
	//	读取文件头
	InitFileHead(&fh,0,"",0);
	if(EOF == fscanf(pfIn, "%s %s %d %u\n", fh.mark , fh.srcfile , &(fh.count) , &(fh.password) ))
		return UNKNOW;
#ifdef _DEBUG_
	printf("%d", ftell(pfIn));
#endif
	//	判断标志是否正确
	printf("检验文件中\n");
	ret = ConfirmMark(MARK,fh.mark);
	if(ConfirmError(ret))
	{
		DestroyFileHead(&fh);
		fclose(pfIn);
		pfIn=NULL;
		return ret;
	}
	printf("检验成功!\n");

	//	判断密码是否正确
	ret = ConfirmPwd(pwd,fh.password);
	if(ConfirmError(ret))
	{
		DestroyFileHead(&fh);
		fclose(pfIn);
		pfIn=NULL;
		return ret;
	}
	printf("密码正确\n");

	//	读取字符频率表
	printf("读取字符频率表中\n");
	ret = ReadFreqList(&FL,pfIn,fh.count);
	if(ConfirmError(ret))
	{
		DestroyFileHead(&fh);
		DestroyFreqList(FL);
		fclose(pfIn);
		pfIn=NULL;
		return ret;
	}
	printf("读取成功！\n");

	//	从压缩包解压数据
	printf("解压数据中\n");
	ret = ReadCompressFile(pfIn,FL,fh.srcfile);
	if(ConfirmError(ret))
	{
		DestroyFileHead(&fh);
		DestroyFreqList(FL);
		fclose(pfIn);
		pfIn=NULL;
		return ret;
	}
	printf("解压成功\n");

	DestroyFreqList(FL);
	DestroyFileHead(&fh);
	fclose(pfIn);
	pfIn=NULL;
	return OK;
}

//	解压
Status Decompress(char srcfile[FILENAMEMAXSIZE],unsigned int pwd)
{
	return HufDecompress( srcfile, pwd);
}
