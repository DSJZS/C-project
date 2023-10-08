#define _CRT_SECURE_NO_WARNINGS 1


#include "FreqList.h"


//	��Ƶ���б��в���Ƶ��(Ȩ��)��͵Ľ�㣬�����������±�
static int SearchLowFreq(FreqList FL,int count)
{
	int i = 0;	//ѭ����������
	int low = 0;	//	��¼Ŀ������±�

	while(FL[low].parent != -1)
		++low;

	for(i=0;i<count;++i)
	{
		if( (FL[i].cInfo.freq <= FL[low].cInfo.freq) && (FL[i].parent == -1) )
		{
			low = i;
		}
	}
	return low;
}
//	�����ַ�Ƶ�ʱ�
Status CreateFreqList(FreqList* FL,char* srcfile, int* count)
{
	long long freq[256] = {0};//	��¼�����ַ���Ƶ�ʣ�ÿ���ַ����±�Ϊ��ASCII��
	unsigned char ch = 0;	//	��ʱ����ַ�����
	int i = 0;	//	�ⲿѭ����������
	int j = 0;	//	�ڲ�ѭ����������
	

	FILE* pfIn = fopen(srcfile,"rb");
	int filelength = get_file_size(pfIn);

	if(pfIn == NULL)
	{
		return NOFOUND;
	}

	while(--filelength)
	{
		ch = fgetc(pfIn);
		if(ferror(pfIn))
			return UNKNOW;
		++( freq[ch] );
	}
	fclose(pfIn);
	pfIn = NULL;

	for( i = 0 ; i < 256 ; ++i)	//	��¼�ļ�������˼����ַ�
	{
		if(freq[i] != 0)
			++(*count);
	}

	// ���ݹ��������Ĺ�ʽ��n��Ҷ�ӽ��Ĺ����������һ����2n-1��
	(*FL) = (Freq*)malloc( sizeof(Freq) * ( 2 * (*count) - 1) );
	if((*FL) == NULL)
		return OVERFLOW;

	//	���δ�����������ĸ���Ҷ�ӽڵ㣬����ʼ������
	for( i = 0 ; i < (*count) ; ++i)
	{

		while(freq[j] == 0)
			++j;
		(*FL)[i].cInfo.c = (char)j;
		(*FL)[i].cInfo.freq = freq[j];
		(*FL)[i].lch = -1;
		(*FL)[i].rch = -1;
		(*FL)[i].parent = -1;
		++j;
	}

	//	������������
	for( i = (*count) ; i < ( 2 * (*count) - 1) ; ++i)
	{
		int lch = 0,rch = 0;
		lch = SearchLowFreq((*FL),i);
		(*FL)[lch].parent = i;
		rch = SearchLowFreq((*FL),i);
		(*FL)[rch].parent = i;

		(*FL)[i].lch = lch;
		(*FL)[i].rch = rch;
		(*FL)[i].parent = -1;
		(*FL)[i].cInfo.freq = (*FL)[lch].cInfo.freq + (*FL)[rch].cInfo.freq;
		(*FL)[i].cInfo.c = -1;
	}

	return OK;
}
// ��ȡ�ַ�Ƶ�ʱ�
Status ReadFreqList(FreqList* FL,FILE* pfIn, int count)
{
	int i = 0;	//	ѭ����������
	(*FL) = (Freq*)malloc( sizeof(Freq) * ( 2 * count - 1) );
	if((*FL) == NULL)
		return OVERFLOW;

	for(i=0;i<count;++i)
	{
		if(EOF == fscanf(pfIn,"-%c-%lld\n", &((*FL)[i].cInfo.c), &((*FL)[i].cInfo.freq)))
			return UNKNOW;
		(*FL)[i].lch = (*FL)[i].rch = (*FL)[i].parent = -1;
	}

	//	������������
	for( i = count ; i < ( 2 * count - 1) ; ++i)
	{
		int lch = 0,rch = 0;
		lch = SearchLowFreq((*FL),i);
		(*FL)[lch].parent = i;
		rch = SearchLowFreq((*FL),i);
		(*FL)[rch].parent = i;

		(*FL)[i].lch = lch;
		(*FL)[i].rch = rch;
		(*FL)[i].parent = -1;
		(*FL)[i].cInfo.freq = (*FL)[lch].cInfo.freq + (*FL)[rch].cInfo.freq;
		(*FL)[i].cInfo.c = -1;
	}

	return OK;
}
//	�����ַ�Ƶ�ʱ�
void DestroyFreqList(FreqList FL)
{
	free(FL);
}