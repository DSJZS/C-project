#ifndef __CDULINKLIST_H__
#define __CDULINKLIST_H__

#include <stdlib.h>

typedef int ElemType;

typedef struct DuLNode	// double linked list
{
	ElemType data;	// 数据域
	struct DuLNode *prior,*next;	// 指针域，分别存放指向前趋和后继的指针
	
}DuLNode, *DuLinkList;

// 初始化双向链表
int InitList_DuL(DuLinkList* L);
// 销毁双向链表
void DestroyList_DuL(DuLinkList* L);
// 通过前插法用空表创建一个n个元素的双向链表，并通过一个create函数为所有元素赋值
int CreateList_DuL_H(DuLinkList L, int n, void(*create)(ElemType* e));
// 通过尾插法用空表创建一个n个元素的双向链表，并通过一个create函数为所有元素赋值
int CreateList_DuL_R(DuLinkList L, int n, void(*create)(ElemType* e));
// 对双向链表的每一个元素执行 traval 函数
void TravalList_DuL(DuLinkList L, void(*traval)(ElemType* e));
// 获取双向链表的长度
int GetLength_DuL(DuLinkList L);
// 判断双向链表是否为空
int IsEmpty_DuL(DuLinkList L);
// 输入一个值，通过 find函数 在双向链表中查找值相同的结点，并返回其地址，如果找不到返回 NULL
// find 函数返回 1 时表示找到了相等的元素，返回 0 表示并不是相等的元素
ElemType* FindNode_DuL(DuLinkList L, ElemType data, int(*find)(ElemType* e , ElemType* dest));
// 在双向链表尾部插入元素
int InsertNodeAtEnd_DuL(DuLinkList L, ElemType data);
// 在双向链表的第i个元素插入指定元素
int InsertNode_DuL(DuLinkList L, ElemType data, int i);
// 在双向链表头部插入元素
int InsertNodeAtHead_DuL(DuLinkList L, ElemType data);
// 删除双向链表尾部的元素
void DeleteNodeAtEnd_DuL(DuLinkList L);
// 删除双向链表头部的元素
void DeleteNodeAtHead_DuL(DuLinkList L);
// 删除双向链表所有的元素
void DeleteAllNode_DuL(DuLinkList L);
// 输入一个值，通过 find函数 在双向链表中查找值相同的结点，删除该结点，并返回 1，如果没有该结点返回 0
// find 函数返回 1 时表示找到了相等的元素，返回 0 表示并不是相等的元素
int DeleteNode_DuL(DuLinkList L, ElemType data, int(*find)(ElemType* e , ElemType* dest));

#endif