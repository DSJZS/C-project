#ifndef __CSQQUEUE_H__
#define __CSQQUEUE_H__

/*  ��˳���Ϊѭ��˳���  */

#include <stdio.h>
#include <stdlib.h>

typedef int QElemType;

typedef struct SqQueue{
	QElemType* data;	// ָ�������ݵĿռ�
	int Capacity;	//	��������
	int front;	// ���±����ͷָ��
	int rear;	// ���±����βָ��
}SqQueue;

// ��ʼ��˳���
int InitQueue_SqQ(SqQueue* Q, int capacity);
// ���˳���
void ClearQueue_SqQ(SqQueue* Q);
// ���˳��ӳ���
int GetLength_SqQ(SqQueue* Q);
// ˳������
int EnQueue_SqQ(SqQueue* Q, QElemType e);
// ˳��ջ����
int DeQueue_SqQ(SqQueue* Q, QElemType* e);
// ��ȡͷԪ��
int GetHead_SqQ(SqQueue* Q, QElemType* e);
// ɾ��˳���
void DestroyQueue_SqQ(SqQueue* Q);

#endif