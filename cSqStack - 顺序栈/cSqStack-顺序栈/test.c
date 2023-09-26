#define _CRT_SECURE_NO_WARNINGS 1

#include "SqStack.h"

int main()
{
	SqStack S;
	int i;
	InitStack_SqS(&S,5);
	i = IsEmpty_SqS(&S);
	i = GetLength_SqS(&S);
	Push_SqS(&S,101);
	Push_SqS(&S,102);
	i = IsEmpty_SqS(&S);
	i = GetLength_SqS(&S);
	Pop_SqS(&S,NULL);
	i = IsEmpty_SqS(&S);
	i = GetLength_SqS(&S);
	i = GetTop_SqS(&S,NULL);
	DestroyStack_SqS(&S);
	return 0;
}