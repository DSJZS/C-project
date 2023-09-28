#define _CRT_SECURE_NO_WARNINGS 1

#include "cSqQueue.h"

int InitQueue_SqQ(SqQueue* Q, int capacity)
{
	Q->Capacity = capacity+1;
	Q->data = (QElemType*)malloc(sizeof(QElemType)*(capacity+1));
	if(Q->data == NULL)
		return 0;
	Q->front = Q->rear = 0;
	return 1;
}

int GetLength_SqQ(SqQueue* Q)
{
	return (Q->rear - Q->front + Q->Capacity) % Q->Capacity;
}

int EnQueue_SqQ(SqQueue* Q, QElemType e)
{
	if( (Q->rear+1)%Q->Capacity == Q->front )
		return 0;
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % Q->Capacity;
	return 1;
}

int DeQueue_SqQ(SqQueue* Q, QElemType* e)
{
	if(Q->front == Q->rear)
		return 0;
	*e = Q->data[Q->front];
	Q->front = (Q->front + 1) % Q->Capacity;
	return 1;
}

int GetHead_SqQ(SqQueue* Q, QElemType* e)
{
	if(Q->front == Q->rear)
		return 0;
	*e = Q->data[Q->front];
	return 1;
}

void DestroyQueue_SqQ(SqQueue* Q)
{
	free(Q->data);
	Q->data = NULL;
	Q->Capacity = 0;
	Q->front = Q->rear = 0;
}

void ClearQueue_SqQ(SqQueue* Q)
{
	Q->front = Q->rear = 0;
}