#ifndef __CLINKQUEUE_H__
#define __CLINKQUEUE_H__
 
#include <stdlib.h>
#include "BinLinkList.h"

typedef BiTree QElemType;

typedef struct QNode{
	QElemType data;		// 数据域
	struct QNode* next;	// 指针域
}QNode,*QueuePtr;

typedef struct LinkQueue{
	QueuePtr front;	// 队头指针
	QueuePtr rear;	// 队尾指针
}LinkQueue;

// 链队初始化
int InitQueue_LQ(LinkQueue* Q);
// 销毁链队
int DestroyQueue_LQ(LinkQueue* Q);
// 链队入队
int EnQueue_LQ(LinkQueue* Q, QElemType e);
// 链队出队
int DeQueue_LQ(LinkQueue* Q, QElemType* e);
// 获得顶部元素
int GetHead_LQ(LinkQueue* Q, QElemType* e);
// 判断链队是否为空对
int IsEmpty_LQ(LinkQueue* Q);

#endif