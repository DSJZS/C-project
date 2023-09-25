#define _CRT_SECURE_NO_WARNINGS 1

#include "cDuLinkList.h"
#include <stdio.h>

void create(ElemType* e)
{
	scanf("%d", e);
}

void traval(ElemType* e)
{
	printf("%d\n", *e);
}

int find(ElemType* e , ElemType* dest)
{
	if( *e == *dest )
		return 1;
	else
		return 0;
}

int main()
{
	DuLinkList L = NULL;
	int i = 0;
	InitList_DuL(&L);
	i = IsEmpty_DuL(L);
	CreateList_DuL_R(L,5,create);
	i = IsEmpty_DuL(L);
	TravalList_DuL(L, traval);
	i = GetLength_DuL(L);
	*(FindNode_DuL(L,4,find)) = 44;
	InsertNodeAtEnd_DuL(L,10086);
	InsertNode_DuL(L,100,5);
	InsertNode_DuL(L,101,5);
	InsertNodeAtHead_DuL(L,103);
	i = GetLength_DuL(L);
	DeleteNodeAtHead_DuL(L);
	DeleteNodeAtEnd_DuL(L);
	DeleteNode_DuL(L,2,find);
	DeleteAllNode_DuL(L);
	DestroyList_DuL(&L);
	return 0;
}