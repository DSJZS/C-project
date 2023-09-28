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
int InitQueue(SqQueue* Q, int capacity);
// ���˳���
void ClearQueue(SqQueue* Q);
// ���˳��ӳ���
int GetLength(SqQueue* Q);
// ˳������
int EnQueue(SqQueue* Q, QElemType e);
// ˳��ջ����
int DeQueue(SqQueue* Q, QElemType* e);
// ��ȡͷԪ��
int GetHead(SqQueue* Q, QElemType* e);
// ɾ��˳���
void DestroyQueue(SqQueue* Q);;
#endif