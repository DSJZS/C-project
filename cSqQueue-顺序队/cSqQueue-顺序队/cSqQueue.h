#ifndef __CSQQUEUE_H__
#define __CSQQUEUE_H__

/*  本顺序队为循环顺序队  */

#include <stdio.h>
#include <stdlib.h>

typedef int QElemType;

typedef struct SqQueue{
	QElemType* data;	// 指向存放数据的空间
	int Capacity;	//	队列容量
	int front;	// 用下标代替头指针
	int rear;	// 用下标代替尾指针
}SqQueue;

// 初始化顺序队
int InitQueue(SqQueue* Q, int capacity);
// 清空顺序队
void ClearQueue(SqQueue* Q);
// 获得顺序队长度
int GetLength(SqQueue* Q);
// 顺序队入队
int EnQueue(SqQueue* Q, QElemType e);
// 顺序栈出队
int DeQueue(SqQueue* Q, QElemType* e);
// 获取头元素
int GetHead(SqQueue* Q, QElemType* e);
// 删除顺序队
void DestroyQueue(SqQueue* Q);;
#endif