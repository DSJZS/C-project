#ifndef __SQSTACK_H__
#define __SQSTACK_H__

#include<stdlib.h>

typedef int SElemType;

typedef struct SqStack{
	SElemType* top;		//	栈顶指针
	SElemType* base; 	//	栈底指针
	int stacksize;	// 栈可用最大容量
}SqStack;


// 初始化顺序栈
int InitStack_SqS(SqStack* S, int stackSize);
// 判断顺序栈是否为空
int IsEmpty_SqS(SqStack* S);
// 获得顺序栈长度
int GetLength_SqS(SqStack* S);
// 清空顺序栈
void ClearStack_SqS(SqStack* S);
// 销毁顺序栈
void DestroyStack_SqS(SqStack* S);
// 顺序栈入栈
int Push_SqS(SqStack* S, SElemType e);
// 顺序栈出栈,e 为NULL时仅删除栈顶元素
int Pop_SqS(SqStack* S, SElemType* e);
// 将顺序栈顶部的元素赋值到 e指向的元素
int GetTop_SqS(SqStack* S, SElemType* e);
#endif