#define _CRT_SECURE_NO_WARNINGS 1

#include "SqStack.h"

int InitStack_SqS(SqStack* S, int stackSize)
{
	S->base = (SElemType*)malloc(sizeof(SElemType)*stackSize);
	if( !(S->base) )
		return 0;
	S->stacksize = stackSize;
	S->top = S->base;
	return 1;
}

int IsEmpty_SqS(SqStack* S)
{
	if( S->top == S->base )
		return 1;
	else
		return 0;
}

int GetLength_SqS(SqStack* S)
{
	return (  S->top - S->base  );
}

void ClearStack_SqS(SqStack* S)
{
	if(S->base)
		S->top = S->base;
}

void DestroyStack_SqS(SqStack* S)
{
	if(S->base)
	{
		free(S->base);
		S->stacksize = 0;
		S->base = NULL;
		S->top = NULL;
	}
}

int Push_SqS(SqStack* S, SElemType e)
{
	if(S->top - S->base == S->stacksize)
		return 0;
	*(S->top) = e;	// *S->top++ = e;
	++(S->top);
	return 1;
}

int Pop_SqS(SqStack* S, SElemType* e)
{
	if(S->top == S->base)
		return 0;
	--(S->top);	// *e = *--S-top
	if(e != NULL)
		*e = *(S->top);
	return 1;
}

int GetTop_SqS(SqStack* S, SElemType* e)
{
	if(e)
	{
		*e = *(S->top - 1);
		return 1;
	}
	return 0£»
}