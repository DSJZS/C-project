#define _CRT_SECURE_NO_WARNINGS 1


#include "cLinkList.h"

int InitList_L(LinkList* L)
{
	LinkList tmp = (LinkList)malloc(sizeof(Lnode));	// 创建头结点
	if(tmp == NULL)
		return 0;
	*L = tmp;
	(*L)->next = NULL;	// 将头结点指针域置空
	return 1;
}

int ListEmpty_L(LinkList L)
{
	if(L->next == NULL)
		return 1;
	else
		return 0;
}

void DestroyList_L(LinkList* L)
{
	Lnode* p = NULL;
	
	while((*L))
	{
		p=(*L);
		(*L)=(*L)->next;
		free(p);
	}

}

void ClearList_L(LinkList L)
{
	Lnode* p = L->next;
	L->next = NULL;
	L = p;
	while(L)
	{
		p=L;
		L=L->next;
		free(p);
	}
}

int ListLength_L(LinkList L)
{
	int count = 0;
	while(L->next)
	{
		count++;
		L = L->next;
	}
	return count;
}

int GetElem_L(LinkList L, int i, ElemType* e)
{
	Lnode* p = L->next;
	int j = 1;
	while(p && j<i)
	{
		++j;
		p=p->next;
	}
	if(!p || j>i)
		return 0;
	*e = p->data;
	return 1;
}

Lnode* LocateElem_L(LinkList L, ElemType e)
{
	Lnode* p = L->next;
	while(p && (p->data != e))
	{
		p = p->next;
	}
	return p;
}

int InsertElem_L(LinkList L, int i ,ElemType* e)
{
	Lnode* p = L;
	int j = 0;
	Lnode* tmp = NULL;
	while(p && j<(i-1)) // i-1=5-1=4,j=0
	{
		p=p->next;
		j++;
	}
	if(!p && j >i-1)
		return 0;

	tmp = (Lnode*)malloc(sizeof(Lnode));
	if(tmp==NULL)
		return 0;
	tmp->next = p->next;
	tmp->data = *e;
	p->next = tmp;
	return 1;

}

int DeleteElem_L(LinkList L, int i ,ElemType* e)
{
	Lnode* p = L;
	Lnode* tmp = NULL;
	int j = 0;
	while(p->next && j<i-1 )
	{
		p=p->next;
		++j;
	}
	if(!(p->next) || j>i-1)
	{
		return 0;
	}
	tmp = p->next->next;
	*e = p->next->data;
	free(p->next);
	p->next = tmp;
	return 1;
}

void CreateList_H(LinkList* L, int n)
{
	int i = 0;
	Lnode* p = NULL;
	(*L) = (LinkList)malloc(sizeof(Lnode));
	(*L)->next = NULL;

	for(i=n;i>0;--i)
	{
		p = (Lnode*)malloc(sizeof(Lnode));
		scanf("%d", &(p->data));
		p->next = (*L)->next;
		(*L)->next = p;
	}
}

void CreateList_R(LinkList* L, int n)
{
	int i = 0;
	Lnode* p = NULL, *r = NULL;
	(*L) = (LinkList)malloc(sizeof(Lnode));
	(*L)->next = NULL;
	r = *L;

	for(i=0;i<n;++i)
	{
		p = (Lnode*)malloc(sizeof(Lnode));
		scanf("%d", &(p->data));
		p->next = NULL;
		r->next = p;
		r=p;
	}

}