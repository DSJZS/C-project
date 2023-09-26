#define _CRT_SECURE_NO_WARNINGS 1

#include "cLinkStack.h"

int main()
{
	LinkStack S;
	int i = 0;
	InitStack_LS(&S);
	i = IsEmpty_LS(S);
	Push_LS(&S,111);
	Push_LS(&S,222);
	Push_LS(&S,333);
	Push_LS(&S,444);
	i = IsEmpty_LS(S);
	i = GetLength_LS(S);
	GetTop_LS(S,&i);
	ClearStack_LS(&S);

	return 0;
}