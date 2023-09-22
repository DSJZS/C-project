#define _CRT_SECURE_NO_WARNINGS 1

#include "cLinkList.h"

int main()
{
	LinkList L = NULL;
	int i  = 106;
	CreateList_R(&L,6);
	InsertElem_L(L,1,&i);
	i = 107;
	InsertElem_L(L,2,&i);
	i = ListEmpty_L(L);
	i = ListLength_L(L);
	
	GetElem_L(L,2,&i);
	DeleteElem_L(L,3,&i);
	GetElem_L(L,1,&i);
	ClearList_L(L);
	DestroyList_L(&L);
	return 0;
}
