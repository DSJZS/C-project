#define _CRT_SECURE_NO_WARNINGS 1

#include "huf_decompress.h"

//	ȷ������
static Status ConfirmPwd(unsigned int pwd1,unsigned int pwd2)
{
	if(pwd1 == pwd2)
		return OK;
	else
		return WRONGPWD;
}
//	ȷ�ϱ�ʶ
static Status ConfirmMark(char* mark1,char* mark2)
{
	if( strcmp(mark1,mark2) == 0)
		return OK;
	else
		return WRONGMARK;
}
//	������ѹ�ļ�
static Status ReadCompressFile(FILE* pfIn,FreqList FL,char* destfile)
{
	FILE* pfOut = fopen(destfile,"wb");
	int root = 0;	//	��¼�ַ�Ƶ�ʱ������±�
	int index = 0;	//	���ڼ�¼�±�
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
		unsigned char ch = 0;	//	��ʱ����ַ�����
		
		int j = 0;	//	��Χ��1-8	����λ����

		if(!filelength)
			break;
		filelength--;

		ch = fgetc(pfIn);
		if(ferror(pfIn))
			return UNKNOW;

		while(j != 8)
		{
			if( (ch & (1<<(7-j))) == 0)	//	��0��1
				index = FL[index].lch;
			else
				index = FL[index].rch;
			if(FL[index].lch == -1)	//	���������Ľ��Ķ���Ϊ0��2��û�ж�Ϊ1�Ľ�㡣
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

//	�����������ѹ
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
	//	��ȡ�ļ�ͷ
	InitFileHead(&fh,0,"",0);
	if(EOF == fscanf(pfIn, "%s %s %d %u\n", fh.mark , fh.srcfile , &(fh.count) , &(fh.password) ))
		return UNKNOW;
#ifdef _DEBUG_
	printf("%d", ftell(pfIn));
#endif
	//	�жϱ�־�Ƿ���ȷ
	printf("�����ļ���\n");
	ret = ConfirmMark(MARK,fh.mark);
	if(ConfirmError(ret))
	{
		DestroyFileHead(&fh);
		fclose(pfIn);
		pfIn=NULL;
		return ret;
	}
	printf("����ɹ�!\n");

	//	�ж������Ƿ���ȷ
	ret = ConfirmPwd(pwd,fh.password);
	if(ConfirmError(ret))
	{
		DestroyFileHead(&fh);
		fclose(pfIn);
		pfIn=NULL;
		return ret;
	}
	printf("������ȷ\n");

	//	��ȡ�ַ�Ƶ�ʱ�
	printf("��ȡ�ַ�Ƶ�ʱ���\n");
	ret = ReadFreqList(&FL,pfIn,fh.count);
	if(ConfirmError(ret))
	{
		DestroyFileHead(&fh);
		DestroyFreqList(FL);
		fclose(pfIn);
		pfIn=NULL;
		return ret;
	}
	printf("��ȡ�ɹ���\n");

	//	��ѹ������ѹ����
	printf("��ѹ������\n");
	ret = ReadCompressFile(pfIn,FL,fh.srcfile);
	if(ConfirmError(ret))
	{
		DestroyFileHead(&fh);
		DestroyFreqList(FL);
		fclose(pfIn);
		pfIn=NULL;
		return ret;
	}
	printf("��ѹ�ɹ�\n");

	DestroyFreqList(FL);
	DestroyFileHead(&fh);
	fclose(pfIn);
	pfIn=NULL;
	return OK;
}

//	��ѹ
Status Decompress(char srcfile[FILENAMEMAXSIZE],unsigned int pwd)
{
	return HufDecompress( srcfile, pwd);
}
