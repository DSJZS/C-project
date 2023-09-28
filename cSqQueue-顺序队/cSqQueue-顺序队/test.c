#define _CRT_SECURE_NO_WARNINGS 1

#include "cSqQueue.h"

int main()
{
	SqQueue Q;
	int i = 0;
	InitQueue(&Q,3);
	EnQueue(&Q, 1);
	EnQueue(&Q, 2);
	EnQueue(&Q, 3);
	DeQueue(&Q, &i);
	EnQueue(&Q, 4);
	DeQueue(&Q, &i);
	EnQueue(&Q, 5);
	GetHead(&Q,&i);
	ClearQueue(&Q);
	return 0;
}