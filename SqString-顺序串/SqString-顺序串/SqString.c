#define _CRT_SECURE_NO_WARNINGS 1

#include "SqString.h"

int index_BF(SqString* S,SqString* T,int pos)
{
	int i = pos;	
	int j = 0;

	if(  (i<S->length) < (j<T->length)  )
		return -1;
	
	while( (i<S->length) && (j<T->length) )
	{	
		if(S->ch[i] == T->ch[j])
		{
			++i,++j;
		}
		else
		{
			i = i-j+1;
			j = 0;
		}
	}
	if(j >= T->length)
		return (i-T->length);
	else
		return -1;
}

static void GetNext(SqString* T,int* next)
{
	int j = -1;
	int i = 0;	// 循环计数变量
	next[0] = -1;
	
	while(i < T->length)
	{
		if(  (j==-1) || (T->ch[i] == T->ch[j])  )
		{
			++i,++j;
			if(i>=T->length)
				break;
			if(T->ch[i] != T->ch[j])
				next[i] = j;
			else
				next[i] = next[j];
		}
		else
		{
			j = next[j];
		}
	}
}

int index_KMP(SqString* S,SqString* T,int pos)
{
	int i = pos;	
	int j = 0;

	int* next = (int*)malloc( sizeof(int) * (T->length) );
	GetNext(T,next);

	if(  (i<S->length) < (j<T->length)  )
		return -1;

	while( (i<S->length) && (j<T->length) )
	{	
		if(  (j==-1)  ||  (S->ch[i] == T->ch[j])  )
		{
			++i,++j;
		}
		else
		{
			j = next[j];
		}
	}

	free(next);

	if(j >= T->length)
		return (i-T->length);
	else
		return -1;
}