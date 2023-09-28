#define _CRT_SECURE_NO_WARNINGS 1

#include "cLinkQueue.h"

int InitQueue_LQ(LinkQueue* Q)
{
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if(Q->front == NULL)
		return 0;
	Q->front->next = NULL;
	return 1;
}

int DestroyQueue_LQ(LinkQueue* Q)
{
	QueuePtr p,q;
	p = Q->front;
	q = p;

	while(p)
	{
		q = p;
		p = p->next;
		free(q);
	}

	Q->front = Q->rear = NULL;
}

int EnQueue_LQ(LinkQueue* Q, QElemType e)
{
	Q->rear->next = (QNode*)malloc(sizeof(QNode));
	if( !(Q->rear->next)  )
		return 0;
	Q->rear = Q->rear->next;
	Q->rear->data = e;
	Q->rear->next = NULL;
	return 1;
}

int DeQueue_LQ(LinkQueue* Q, QElemType* e)
{
	QNode* p = Q->front->next;
	if(Q->front == Q->rear)
		return 0;
	*e = p->data;
	Q->front->next = p->next;
	if(Q->rear == p)
		Q->rear = Q->front;
	free(p);
}