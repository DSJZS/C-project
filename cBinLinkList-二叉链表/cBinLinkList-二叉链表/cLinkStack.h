#ifndef __CLINKSTACK_H__
#define __CLINKSTACK_H__

#include<stdlib.h>
#include "BinLinkList.h"

typedef BiTree SElemType;

typedef struct StackNode{
	SElemType data;
	struct StackNode* next;
}StackNode, *LinkStack;

// 初始化链栈
void InitStack_LS(LinkStack* S);
// 判断链栈是否为空
int IsEmpty_LS(LinkStack S);
// 链栈入栈
int Push_LS(LinkStack* S, SElemType e);
// 链栈出栈,e 为NULL时仅删除栈顶元素
int Pop_LS(LinkStack* S, SElemType* e);
// 获得链栈长度
int GetLength_LS(LinkStack S);
// 清空链栈
void ClearStack_LS(LinkStack* S);
// 销毁链栈
void DestroyStack_LS(LinkStack* S);
// 将链栈顶部的元素赋值到 e指向的元素
int GetTop_LS(LinkStack S, SElemType* e);


#endif