#ifndef __SQSTACK_H__
#define __SQSTACK_H__

#include<stdlib.h>

typedef int SElemType;

typedef struct SqStack{
	SElemType* top;		//	ջ��ָ��
	SElemType* base; 	//	ջ��ָ��
	int stacksize;	// ջ�����������
}SqStack;


// ��ʼ��˳��ջ
int InitStack_SqS(SqStack* S, int stackSize);
// �ж�˳��ջ�Ƿ�Ϊ��
int IsEmpty_SqS(SqStack* S);
// ���˳��ջ����
int GetLength_SqS(SqStack* S);
// ���˳��ջ
void ClearStack_SqS(SqStack* S);
// ����˳��ջ
void DestroyStack_SqS(SqStack* S);
// ˳��ջ��ջ
int Push_SqS(SqStack* S, SElemType e);
// ˳��ջ��ջ,e ΪNULLʱ��ɾ��ջ��Ԫ��
int Pop_SqS(SqStack* S, SElemType* e);
// ��˳��ջ������Ԫ�ظ�ֵ�� eָ���Ԫ��
int GetTop_SqS(SqStack* S, SElemType* e);
#endif