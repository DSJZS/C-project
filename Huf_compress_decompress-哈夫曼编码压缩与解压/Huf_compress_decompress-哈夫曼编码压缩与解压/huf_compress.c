#define _CRT_SECURE_NO_WARNINGS 1

#include "huf_compress.h"


// 给文件打上后缀，比如zip压缩的后缀是zip，这里是FR压缩，所以后缀是FR
static Status SuffixingFile(char* filename,char* suffix)
{
	if( (strlen(filename) + strlen(suffix) + 2) > FILENAMEMAXSIZE )
		return LONGNAME;
	strcat(filename,".");
	strcat(filename,suffix);
	return OK;
}

//	创建压缩文件
static Status CreatingCompressFile(FreqList FL, HufCodeList HCL,int count, char* srcfile,char* destfile,unsigned int pwd)
{
	FileHead fh;	
	FILE* pfIn = NULL;
	FILE* pfOut = NULL;
	int index[256] = {0};//	记录各个字符的在哈夫曼编码里的下标
	int i = 0;	//	循环计数变量
	int j = 0;	//	范围：1-8	用于位操作
	unsigned char value = 0;	//
	int filelength = 0;


	InitFileHead(&fh,pwd,srcfile,count);

	if(SuffixingFile(destfile,fh.mark) == LONGNAME)	//	判断字符串是否过长
		return LONGNAME;
	pfIn = fopen(srcfile,"rb");
	pfOut = fopen(destfile,"wb");
	filelength = get_file_size(pfIn);

	if(pfIn == NULL)
		return NOFOUND;
	if(pfOut == NULL)
		return UNKNOW;
	

	for(i=0;i<count;i++)
	{
		index[ (int)(HCL[i].c) ] = i;
	}

	//	在压缩包中存入标识、原文件名、字符种类数量、密码
	if(fprintf(pfOut,"%s %s %d %u\n", fh.mark , fh.srcfile , fh.count , fh.password ) < 0)
		return UNKNOW;

	//	在压缩包中存入字符频率表
	for(i=0;i<count;i++)
	{

		if(fprintf(pfOut,"-%c-%lld\n", FL[i].cInfo.c, FL[i].cInfo.freq) < 0)
			return UNKNOW;
	}

	//	压缩数据到压缩包
	while(1)
	{
		unsigned char ch = 0;	//	临时存放字符变量

		if(!filelength)
			break;
		filelength--;

		ch = fgetc(pfIn);
		if(ferror(pfIn))
			return UNKNOW;
		/*if(feof(pfIn))
		break;*/
		
		for( i=0; HCL[ index[ch] ].hcode[i] != '\0' ; ++i)
		{
			if(  HCL[ index[ch] ].hcode[i] == '1' )
				value |= (1<<(7-j));
			++j;
			if(j % 8 == 0)
			{
				if(1 != fwrite(&value,sizeof(value),1,pfOut))
					return UNKNOW;
				j = 0;
				value = 0;
			}
		}
	}
	if(j != 0)
	{
		if(EOF == fputc(value,pfOut))
			return UNKNOW;
	}
	


	DestroyFileHead(&fh);
	fclose(pfIn);
	pfIn = NULL;
	fclose(pfOut);
	pfOut = NULL;
	return OK;
}

//	哈夫曼编码压缩
					//	要压缩的文件	//	压缩到的文件		// 纯数字密码
static Status HufCompress(char srcfile[256],char destfile[256],int pwd)
{
	FreqList FL = NULL;	//	字符频率表(哈夫曼树)
	HufCodeList HCL = NULL;	//	哈夫曼编码表
	int count = 0;	//	记录字符个数
	Status ret = OK;	//	记录返回值
	int before = 0;	//	记录压缩前文件大小
	int after = 0;	//	记录压缩后文件大小
	FILE* pfIn = NULL;
	FILE* pfOut = NULL;

	pfIn = fopen(srcfile,"rb");
	before = get_file_size(pfIn);
	fclose(pfIn);

	printf("构建哈夫曼树中\n");
	ret = CreateFreqList(&FL,srcfile,&count);	//	创建哈夫曼树
	if( ConfirmError(ret) )
	{
		DestroyFreqList(FL);
		return ret;
	}
	printf("构建成功！\n");

	printf("构建哈夫曼编码表中\n");
	ret = CreateHufCodeList(FL,&HCL,count);//	创建哈夫曼编码表
	if( ConfirmError(ret) )
	{
		DestroyFreqList(FL);
		DestroyFreqList(FL);
		return ret;
	}
	printf("构建成功！\n");

	printf("压缩文件中\n");
	ret = CreatingCompressFile(FL, HCL,count,srcfile,destfile,pwd);	//	压缩文件
	if( ConfirmError(ret) )
	{
		DestroyFreqList(FL);
		DestroyFreqList(FL);
		return ret;
	}
	printf("压缩成功！\n");
	
	pfOut = fopen(destfile,"rb");
	after = get_file_size(pfOut);
	fclose(pfOut);

	printf("%dByte -> %dByte  压缩率：%lf",before,after,(double)after/(double)before);

	DestroyFreqList(FL);
	DestroyHufCodeList(HCL,count);
	return OK;
}


//	压缩
					//	要压缩的文件	//	压缩到的文件		// 纯数字密码
Status Compress(char srcfile[256],char destfile[256],int pwd)
{

	return HufCompress(srcfile,destfile, pwd);
}