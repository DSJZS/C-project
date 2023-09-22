#ifndef __CLINKLIST_H__
#define __CLINKLIST_H__

#include<stdio.h>
#include<stdlib.h>

//typedef struct{
//	char num[8];
//	char name[8];
//	int score;
//}ElemType;
typedef int ElemType;

typedef struct Lnode{
	ElemType data;	
	struct Lnode* next;
}Lnode, *LinkList;	// LinkListΪָ��ṹ��Lnode��ָ������

// ������ĳ�ʼ��
int InitList_L(LinkList* L);
// �жϵ������Ƿ�Ϊ��
int ListEmpty_L(LinkList L);
// �����������
void DestroyList_L(LinkList* L);
// ����������
void ClearList_L(LinkList L);
// ������ı�
int ListLength_L(LinkList L);
// ȡ��������ĵ�i��Ԫ���������ֵ
int GetElem_L(LinkList L, int i, ElemType* e);
// ������ָ��������ȵ�Ԫ�ز��������ַ
Lnode* LocateElem_L(LinkList L, ElemType e);
// �ڵ�i��Ԫ��ǰ�����½ڵ�
int InsertElem_L(LinkList L, int i ,ElemType* e);
// ɾ����i��Ԫ�ؽ��
int DeleteElem_L(LinkList L, int i ,ElemType* e);
// ǰ�巨����һ����ͷ���ĵ�����
void CreateList_H(LinkList* L, int n);
// ��巨����һ����ͷ���ĵ�����
void CreateList_R(LinkList* L, int n);
#endif