#define _CRT_SECURE_NO_WARNINGS 1

#include "SequenceList.h"
int cmp(const void* t1,const void* t2)
{
	return *(int*)t1 - *(int*)t2;
}

int main()
{
	SqList L;
	int test = 10086;
	int tt = 101;
	int ttt = 11;
	InitList_SqList(&L,sizeof(int));
	L.push_back(&L,&test);
	L.push_back(&L,&tt);
	L.push_back(&L,&ttt);
	L.sort(&L,cmp);
	printf("%d\n", *(int*)(L.back(&L)));
	printf("%d\n", *(int*)(L.front(&L)));

	return 0;
}