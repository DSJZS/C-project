#define _CRT_SECURE_NO_WARNINGS 1

#include "HufCodeList.h"


//	创建哈夫曼编码表	
Status CreateHufCodeList(FreqList FL,HufCodeList* HCL,int count)
{
	int i = 0;	//	循环计数变量

	// 根据哈夫曼编码公式由有n个叶子结点的哈夫曼树得到的哈夫曼编码最长为n-1
	// 又由于字符串最后一位必须为 '\0' 所以开辟 n-1 + 1 = n个大小的空间
	// 同时 calloc 会初始化所有空间为 0，所以不用赋值最后一位为'\0'
	char* cd = (char*)calloc( count ,sizeof(char));
	if(cd == NULL)
		return OVERFLOW;


	(*HCL) = (HufCode*)malloc(sizeof(HufCode) * count);
	if((*HCL) == NULL)
		return OVERFLOW;

	for(i=0;i<count;++i)
	{
		int child = i;
		int j = count-2;
		do{
			if(child == FL[ FL[child].parent ].lch)	// 左0右1
				cd[j] = '0';
			else
				cd[j] = '1';
			--j;
			child = FL[child].parent;
		}while(FL[child].parent != -1);
		(*HCL)[i].c = FL[i].cInfo.c;
		(*HCL)[i].hcode = (char*)calloc( count ,sizeof(char));
		if((*HCL)[i].hcode == NULL)
			return OVERFLOW;
		++j;
		strcpy((*HCL)[i].hcode,&(cd[j]));
	}
	free(cd);
	cd=NULL;
	return OK;
}
//	销毁哈夫曼编码表	
void DestroyHufCodeList(HufCodeList HCL,int count)
{
	int i = 0;	//	循环计数变量
	for(i=0;i<count;i++)
	{
		free( HCL[i].hcode );
		HCL[i].hcode = NULL;
	}
	free(HCL);
}