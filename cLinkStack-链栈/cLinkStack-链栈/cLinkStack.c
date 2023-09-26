#define _CRT_SECURE_NO_WARNINGS 1

#include "cLinkStack.h"

void InitStack_LS(LinkStack* S)
{
	*S = NULL;
}

int IsEmpty_LS(LinkStack S)
{
	if(S == NULL)
		return 1;
	else
		return 0;
}

int Push_LS(LinkStack* S, SElemType e)
{
	StackNode* p = (StackNode*)malloc(sizeof(StackNode));
	if(!p)
		return 0;
	p->data = e;
	p->next = *S;
	*S = p;
	return 1;
}

int Pop_LS(LinkStack* S, SElemType* e)
{
	StackNode* p = NULL;
	if(S==NULL)
		return 0;
	p = *S;
	*e = (*S)->data;
	*S = (*S)->next;
	free(p);
	return 1;
}

int GetLength_LS(LinkStack S)
{
	StackNode* p = S;
	int count = 0;
	if(S == NULL)
		return 0;
	while(p)
	{
		++count;
		p = p->next;
	}
	return count;
}

void ClearStack_LS(LinkStack* S)
{
	StackNode *p, *q;
	p = *S;
	if(p == NULL)
		return;
	while(p)
	{
		q = p;
		p = p->next;
		free(q);
	}
	*S = NULL;
}

void DestroyStack_LS(LinkStack* S)
{
	ClearStack_LS(S);
}

int GetTop_LS(LinkStack S, SElemType* e)
{
	if(e)
	{
		*e = S->data;
		return 1;
	}
	return 0;
}