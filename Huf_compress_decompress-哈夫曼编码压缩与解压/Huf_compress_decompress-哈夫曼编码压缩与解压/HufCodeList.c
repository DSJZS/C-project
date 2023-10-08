#define _CRT_SECURE_NO_WARNINGS 1

#include "HufCodeList.h"


//	���������������	
Status CreateHufCodeList(FreqList FL,HufCodeList* HCL,int count)
{
	int i = 0;	//	ѭ����������

	// ���ݹ��������빫ʽ����n��Ҷ�ӽ��Ĺ��������õ��Ĺ����������Ϊn-1
	// �������ַ������һλ����Ϊ '\0' ���Կ��� n-1 + 1 = n����С�Ŀռ�
	// ͬʱ calloc ���ʼ�����пռ�Ϊ 0�����Բ��ø�ֵ���һλΪ'\0'
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
			if(child == FL[ FL[child].parent ].lch)	// ��0��1
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
//	���ٹ����������	
void DestroyHufCodeList(HufCodeList HCL,int count)
{
	int i = 0;	//	ѭ����������
	for(i=0;i<count;i++)
	{
		free( HCL[i].hcode );
		HCL[i].hcode = NULL;
	}
	free(HCL);
}