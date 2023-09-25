#ifndef __CDULINKLIST_H__
#define __CDULINKLIST_H__

#include <stdlib.h>

typedef int ElemType;

typedef struct DuLNode	// double linked list
{
	ElemType data;	// ������
	struct DuLNode *prior,*next;	// ָ���򣬷ֱ���ָ��ǰ���ͺ�̵�ָ��
	
}DuLNode, *DuLinkList;

// ��ʼ��˫������
int InitList_DuL(DuLinkList* L);
// ����˫������
void DestroyList_DuL(DuLinkList* L);
// ͨ��ǰ�巨�ÿձ���һ��n��Ԫ�ص�˫��������ͨ��һ��create����Ϊ����Ԫ�ظ�ֵ
int CreateList_DuL_H(DuLinkList L, int n, void(*create)(ElemType* e));
// ͨ��β�巨�ÿձ���һ��n��Ԫ�ص�˫��������ͨ��һ��create����Ϊ����Ԫ�ظ�ֵ
int CreateList_DuL_R(DuLinkList L, int n, void(*create)(ElemType* e));
// ��˫�������ÿһ��Ԫ��ִ�� traval ����
void TravalList_DuL(DuLinkList L, void(*traval)(ElemType* e));
// ��ȡ˫������ĳ���
int GetLength_DuL(DuLinkList L);
// �ж�˫�������Ƿ�Ϊ��
int IsEmpty_DuL(DuLinkList L);
// ����һ��ֵ��ͨ�� find���� ��˫�������в���ֵ��ͬ�Ľ�㣬���������ַ������Ҳ������� NULL
// find �������� 1 ʱ��ʾ�ҵ�����ȵ�Ԫ�أ����� 0 ��ʾ��������ȵ�Ԫ��
ElemType* FindNode_DuL(DuLinkList L, ElemType data, int(*find)(ElemType* e , ElemType* dest));
// ��˫������β������Ԫ��
int InsertNodeAtEnd_DuL(DuLinkList L, ElemType data);
// ��˫������ĵ�i��Ԫ�ز���ָ��Ԫ��
int InsertNode_DuL(DuLinkList L, ElemType data, int i);
// ��˫������ͷ������Ԫ��
int InsertNodeAtHead_DuL(DuLinkList L, ElemType data);
// ɾ��˫������β����Ԫ��
void DeleteNodeAtEnd_DuL(DuLinkList L);
// ɾ��˫������ͷ����Ԫ��
void DeleteNodeAtHead_DuL(DuLinkList L);
// ɾ��˫���������е�Ԫ��
void DeleteAllNode_DuL(DuLinkList L);
// ����һ��ֵ��ͨ�� find���� ��˫�������в���ֵ��ͬ�Ľ�㣬ɾ���ý�㣬������ 1�����û�иý�㷵�� 0
// find �������� 1 ʱ��ʾ�ҵ�����ȵ�Ԫ�أ����� 0 ��ʾ��������ȵ�Ԫ��
int DeleteNode_DuL(DuLinkList L, ElemType data, int(*find)(ElemType* e , ElemType* dest));

#endif