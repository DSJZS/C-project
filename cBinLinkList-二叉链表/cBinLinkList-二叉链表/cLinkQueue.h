#ifndef __CLINKQUEUE_H__
#define __CLINKQUEUE_H__
 
#include <stdlib.h>
#include "BinLinkList.h"

typedef BiTree QElemType;

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
int GetHead_LQ(LinkQueue* Q, QElemType* e);
// �ж������Ƿ�Ϊ�ն�
int IsEmpty_LQ(LinkQueue* Q);

#endif