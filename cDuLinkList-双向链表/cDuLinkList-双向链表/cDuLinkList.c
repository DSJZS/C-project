#define _CRT_SECURE_NO_WARNINGS 1

#include "cDuLinkList.h"


int InitList_DuL(DuLinkList* L)
{
	DuLinkList p = (DuLNode*)malloc(sizeof(DuLNode));
	if(!p)
		return 0;
	*L = p;
	(*L)->data = 0;
	(*L)->next = NULL;
	(*L)->prior = NULL;
	return 1;
}

void DestroyList_DuL(DuLinkList* L)
{
	DuLNode* p = *L;
	DuLNode* q = NULL;

	while(p)
	{
		q = p;
		p = p->next;
		free(q);
	}
	*L = NULL;
}

int CreateList_DuL_H(DuLinkList L, int n, void(*create)(ElemType* e))
{
	DuLNode* p = NULL;
	if(L->next != NULL)	// 判断是不是空表
		return 0;
	while(n--)
	{
		p = (DuLNode*)malloc(sizeof(DuLNode));
		if(!p)	// 堆空间不够
			return 0;
		create(&(p->data));
		p->next = L->next;
		p->prior = L;
		if(L->next)	//	L 不为空表时
			L->next->prior = p;
		L->next = p;
	}
	return 1;
}

int CreateList_DuL_R(DuLinkList L, int n, void(*create)(ElemType* e))
{
	DuLNode* p = NULL;
	if(L->next != NULL)	// 判断是不是空表
		return 0;
	while(n--)
	{
		p = (DuLNode*)malloc(sizeof(DuLNode));
		if(!p)	// 堆空间不够
			return 0;
		create(&(p->data));
		L->next = p;
		p->next = NULL;
		p->prior = L;
		L = L->next;
	}
	return 1;
}

void TravalList_DuL(DuLinkList L, void(*traval)(ElemType* e))
{
	L = L->next;

	while(L)
	{
		traval( &(L->data) );
		L = L->next;
	}
}

int GetLength_DuL(DuLinkList L)
{
	int count = 0;
	L = L->next;

	while(L)
	{
		++count;
		L = L->next;
	}
	return count;
}

int IsEmpty_DuL(DuLinkList L)
{
	if(L->next == NULL)
		return 1;
	else
		return 0;
}

ElemType* FindNode_DuL(DuLinkList L, ElemType data, int(*find)(ElemType* e , ElemType* dest))
{
	L = L->next;

	while(L)
	{
		if( find(L,&data) )
			return L;
		L = L->next;
	}
	return NULL;
}

int InsertNodeAtEnd_DuL(DuLinkList L, ElemType data)
{
	DuLNode* p = NULL;
	L = L->next;
	p = (DuLNode*)malloc(sizeof(DuLNode));
	if(!p)
		return 0;
	while(L->next)
	{
		L = L->next;
	}
	p->data = data;
	p->next = NULL;
	p->prior = L;
	L->next = p;

	return 1;
}

int InsertNode_DuL(DuLinkList L, ElemType data, int i)
{
	DuLNode* p = NULL;
	L = L->next;

	while( (--i) && L )
	{
		L = L->next;
	}
	if(!L)
		return 0;
	p = (DuLNode*)malloc(sizeof(DuLNode));
	if(!p)
		return 0;
	p->data = data;
	p->next = L->next;
	p->prior = L;
	if(L->next)	// 如果 L 此时指向的不是最后一个元素
		L->next->prior = p;
	L->next = p;
	return 1;
}

int InsertNodeAtHead_DuL(DuLinkList L, ElemType data)
{
	DuLNode* p = NULL;
	p = (DuLNode*)malloc(sizeof(DuLNode));
	if(!p)
		return 0;
	p->data = data;
	p->next = L->next;
	p->prior = L;
	if(L->next)	// 判断 L 是否为空表
		L->next->prior = p;
	L->next = p;
	return 1;
}

void DeleteNodeAtEnd_DuL(DuLinkList L)
{
	if(L->next == NULL)	//	判断 L 是不是空表
		return;
	L = L->next;
	while(L->next)
	{
		L = L->next;
	}
	L->prior->next = NULL;
	free(L);
}

void DeleteNodeAtHead_DuL(DuLinkList L)
{
	if(L->next == NULL)	//	判断 L 是不是空表
		return;
	L = L->next;
	L->prior->next = L->next;
	free(L);
}

void DeleteAllNode_DuL(DuLinkList L)
{
	DuLNode *p,*q;
	p = L->next;
	q = p;

	while(p)
	{
		q = p;
		p = p->next;
		free(q);
	}
	L->next = NULL;
}

int DeleteNode_DuL(DuLinkList L, ElemType data, int(*find)(ElemType* e , ElemType* dest))
{
	L = L->next;

	while(L)
	{
		if( find(L,&data) )
		{
			if(L->next != NULL)
				L->next->prior = L->prior;
			L->prior->next = L->next;
			free(L);
			return 1;
		}
		L = L->next;
	}
	return 0;
}
