#ifndef __CTREE_H__
#define __CTREE_H__

#define MAX_TREE_SIZE 100
typedef int TElemType;

// 孩子结点
typedef struct CTNode{
	int child;	//	孩子结点下标
	struct CTNode* next;
}*ChildPtr;

// 双亲结点
typedef struct CTBox{
	TElemType data;
	ChildPtr firstchild;	// 孩子链表头指针
}CTBox;

// 树结构
typedef struct CTree{
	CTBox nodes[MAX_TREE_SIZE];
	int r,n;	//记录根节点的下标位置和结点个数
}CTree;


#endif