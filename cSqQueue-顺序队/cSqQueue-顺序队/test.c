#define _CRT_SECURE_NO_WARNINGS 1

#include "cSqQueue.h"

int main()
{
	SqQueue Q;
	int i = 0;
	InitQueue_SqQ(&Q,3);
	EnQueue_SqQ(&Q, 1);
	EnQueue_SqQ(&Q, 2);
	EnQueue_SqQ(&Q, 3);
	DeQueue_SqQ(&Q, &i);
	EnQueue_SqQ(&Q, 4);
	DeQueue_SqQ(&Q, &i);
	EnQueue_SqQ(&Q, 5);
	GetHead_SqQ(&Q,&i);
	ClearQueue_SqQ(&Q);
	return 0;
}