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
}Lnode, *LinkList;	// LinkList为指向结构体Lnode的指针类型

// 单链表的初始化
int InitList_L(LinkList* L);
// 判断单链表是否为空
int ListEmpty_L(LinkList L);
// 单链表的销毁
void DestroyList_L(LinkList* L);
// 单链表的清空
void ClearList_L(LinkList L);
// 求单链表的表长
int ListLength_L(LinkList L);
// 取出单链表的第i个元素数据域的值
int GetElem_L(LinkList L, int i, ElemType* e);
// 查找与指定数据相等的元素并返回其地址
Lnode* LocateElem_L(LinkList L, ElemType e);
// 在第i个元素前插入新节点
int InsertElem_L(LinkList L, int i ,ElemType* e);
// 删除第i个元素结点
int DeleteElem_L(LinkList L, int i ,ElemType* e);
// 前插法建立一个带头结点的单链表
void CreateList_H(LinkList* L, int n);
// 后插法建立一个带头结点的单链表
void CreateList_R(LinkList* L, int n);
#endif