#define _CRT_SECURE_NO_WARNINGS 1

#include "SequenceList.h"

int main()
{
	SqList L;
	int test = 10086;
	InitList_SqList(&L,sizeof(int));
	L.push_back(&L,&test);
	printf("%d\n", *(int*)(L.front(&L)));

	return 0;
}