#define _CRT_SECURE_NO_WARNINGS 1

#include "SequenceList.h"

int main()
{
	SqList L;
	int test = 10086;
	int tt = 101;
	InitList_SqList(&L,sizeof(int));
	L.push_back(&L,&test);
	L.push_back(&L,&tt);
	printf("%d\n", *(int*)(L.get(&L,1)));

	return 0;
}