#ifndef __CLINKSTACK_H__
#define __CLINKSTACK_H__

#include<stdlib.h>
#include "BinLinkList.h"

typedef BiTree SElemType;

typedef struct StackNode{
	SElemType data;
	struct StackNode* next;
}StackNode, *LinkStack;

// ��ʼ����ջ
void InitStack_LS(LinkStack* S);
// �ж���ջ�Ƿ�Ϊ��
int IsEmpty_LS(LinkStack S);
// ��ջ��ջ
int Push_LS(LinkStack* S, SElemType e);
// ��ջ��ջ,e ΪNULLʱ��ɾ��ջ��Ԫ��
int Pop_LS(LinkStack* S, SElemType* e);
// �����ջ����
int GetLength_LS(LinkStack S);
// �����ջ
void ClearStack_LS(LinkStack* S);
// ������ջ
void DestroyStack_LS(LinkStack* S);
// ����ջ������Ԫ�ظ�ֵ�� eָ���Ԫ��
int GetTop_LS(LinkStack S, SElemType* e);


#endif