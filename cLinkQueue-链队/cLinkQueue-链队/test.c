#define _CRT_SECURE_NO_WARNINGS 1

#include "cLinkQueue.h"

int main()
{
	LinkQueue Q;
	int i = 0;
	InitQueue_LQ(&Q);
	EnQueue_LQ(&Q,1);
	EnQueue_LQ(&Q,2);
	EnQueue_LQ(&Q,3);
	EnQueue_LQ(&Q,4);
	EnQueue_LQ(&Q,5);
	DeQueue_LQ(&Q,&i);
	DestroyQueue_LQ(&Q);
	return 0;
}