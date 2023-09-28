#ifndef __CLINKQUEUE_H__
#define __CLINKQUEUE_H__
 
#include <stdlib.h>

typedef int QElemType;

typedef struct QNode{
	QElemType data;		// ������
	struct QNode* next;	// ָ����
}QNode,*QueuePtr;

typedef struct LinkQueue{
	QueuePtr front;	// ��ͷָ��
	QueuePtr rear;	// ��βָ��
}LinkQueue;

// ���ӳ�ʼ��
int InitQueue_LQ(LinkQueue* Q);
// ��������
int DestroyQueue_LQ(LinkQueue* Q);
// �������
int EnQueue_LQ(LinkQueue* Q, QElemType e);
// ���ӳ���
int DeQueue_LQ(LinkQueue* Q, QElemType* e);
// ��ö���Ԫ��
int GetHead(LinkQueue* Q, QElemType* e);
#endif