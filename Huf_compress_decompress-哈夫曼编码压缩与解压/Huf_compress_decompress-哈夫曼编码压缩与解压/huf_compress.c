#define _CRT_SECURE_NO_WARNINGS 1

#include "huf_compress.h"


// ���ļ����Ϻ�׺������zipѹ���ĺ�׺��zip��������FRѹ�������Ժ�׺��FR
static Status SuffixingFile(char* filename,char* suffix)
{
	if( (strlen(filename) + strlen(suffix) + 2) > FILENAMEMAXSIZE )
		return LONGNAME;
	strcat(filename,".");
	strcat(filename,suffix);
	return OK;
}

//	����ѹ���ļ�
static Status CreatingCompressFile(FreqList FL, HufCodeList HCL,int count, char* srcfile,char* destfile,unsigned int pwd)
{
	FileHead fh;	
	FILE* pfIn = NULL;
	FILE* pfOut = NULL;
	int index[256] = {0};//	��¼�����ַ����ڹ�������������±�
	int i = 0;	//	ѭ����������
	int j = 0;	//	��Χ��1-8	����λ����
	unsigned char value = 0;	//
	int filelength = 0;


	InitFileHead(&fh,pwd,srcfile,count);

	if(SuffixingFile(destfile,fh.mark) == LONGNAME)	//	�ж��ַ����Ƿ����
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

	//	��ѹ�����д����ʶ��ԭ�ļ������ַ���������������
	if(fprintf(pfOut,"%s %s %d %u\n", fh.mark , fh.srcfile , fh.count , fh.password ) < 0)
		return UNKNOW;

	//	��ѹ�����д����ַ�Ƶ�ʱ�
	for(i=0;i<count;i++)
	{

		if(fprintf(pfOut,"-%c-%lld\n", FL[i].cInfo.c, FL[i].cInfo.freq) < 0)
			return UNKNOW;
	}

	//	ѹ�����ݵ�ѹ����
	while(1)
	{
		unsigned char ch = 0;	//	��ʱ����ַ�����

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

//	����������ѹ��
					//	Ҫѹ�����ļ�	//	ѹ�������ļ�		// ����������
static Status HufCompress(char srcfile[256],char destfile[256],int pwd)
{
	FreqList FL = NULL;	//	�ַ�Ƶ�ʱ�(��������)
	HufCodeList HCL = NULL;	//	�����������
	int count = 0;	//	��¼�ַ�����
	Status ret = OK;	//	��¼����ֵ
	int before = 0;	//	��¼ѹ��ǰ�ļ���С
	int after = 0;	//	��¼ѹ�����ļ���С
	FILE* pfIn = NULL;
	FILE* pfOut = NULL;

	pfIn = fopen(srcfile,"rb");
	before = get_file_size(pfIn);
	fclose(pfIn);

	printf("��������������\n");
	ret = CreateFreqList(&FL,srcfile,&count);	//	������������
	if( ConfirmError(ret) )
	{
		DestroyFreqList(FL);
		return ret;
	}
	printf("�����ɹ���\n");

	printf("�����������������\n");
	ret = CreateHufCodeList(FL,&HCL,count);//	���������������
	if( ConfirmError(ret) )
	{
		DestroyFreqList(FL);
		DestroyFreqList(FL);
		return ret;
	}
	printf("�����ɹ���\n");

	printf("ѹ���ļ���\n");
	ret = CreatingCompressFile(FL, HCL,count,srcfile,destfile,pwd);	//	ѹ���ļ�
	if( ConfirmError(ret) )
	{
		DestroyFreqList(FL);
		DestroyFreqList(FL);
		return ret;
	}
	printf("ѹ���ɹ���\n");
	
	pfOut = fopen(destfile,"rb");
	after = get_file_size(pfOut);
	fclose(pfOut);

	printf("%dByte -> %dByte  ѹ���ʣ�%lf",before,after,(double)after/(double)before);

	DestroyFreqList(FL);
	DestroyHufCodeList(HCL,count);
	return OK;
}


//	ѹ��
					//	Ҫѹ�����ļ�	//	ѹ�������ļ�		// ����������
Status Compress(char srcfile[256],char destfile[256],int pwd)
{

	return HufCompress(srcfile,destfile, pwd);
}