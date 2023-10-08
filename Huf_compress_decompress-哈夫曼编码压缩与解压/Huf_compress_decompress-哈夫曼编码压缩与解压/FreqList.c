#define _CRT_SECURE_NO_WARNINGS 1


#include "FreqList.h"


//	在频率列表中查找频率(权重)最低的结点，并返回它的下标
static int SearchLowFreq(FreqList FL,int count)
{
	int i = 0;	//循环计数变量
	int low = 0;	//	记录目标结点的下标

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
//	创建字符频率表
Status CreateFreqList(FreqList* FL,char* srcfile, int* count)
{
	long long freq[256] = {0};//	记录各个字符的频率，每个字符的下标为其ASCII码
	unsigned char ch = 0;	//	临时存放字符变量
	int i = 0;	//	外部循环计数变量
	int j = 0;	//	内部循环计数变量
	

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

	for( i = 0 ; i < 256 ; ++i)	//	记录文件间出现了几个字符
	{
		if(freq[i] != 0)
			++(*count);
	}

	// 根据哈夫曼树的公式，n个叶子结点的哈夫曼树结点一共有2n-1个
	(*FL) = (Freq*)malloc( sizeof(Freq) * ( 2 * (*count) - 1) );
	if((*FL) == NULL)
		return OVERFLOW;

	//	依次存入哈夫曼树的各个叶子节点，并初始化它们
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

	//	构建哈夫曼树
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
// 读取字符频率表
Status ReadFreqList(FreqList* FL,FILE* pfIn, int count)
{
	int i = 0;	//	循环计数变量
	(*FL) = (Freq*)malloc( sizeof(Freq) * ( 2 * count - 1) );
	if((*FL) == NULL)
		return OVERFLOW;

	for(i=0;i<count;++i)
	{
		if(EOF == fscanf(pfIn,"-%c-%lld\n", &((*FL)[i].cInfo.c), &((*FL)[i].cInfo.freq)))
			return UNKNOW;
		(*FL)[i].lch = (*FL)[i].rch = (*FL)[i].parent = -1;
	}

	//	构建哈夫曼树
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
//	销毁字符频率表
void DestroyFreqList(FreqList FL)
{
	free(FL);
}