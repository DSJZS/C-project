#define _CRT_SECURE_NO_WARNINGS 1

#include "EightQueens.h"

int main()
{
	SqStack S;
	InitStack_SqS( &S, N);

	Queens(&S,0);


	DestroyStack_SqS( &S);
	system("pause");
	return 0;
}