#ifndef __PCTREE_H__
#define __PCTREE_H__

#define MAX_TREE_SIZE 100
typedef int TElemType;

// 孩子结点
typedef struct CTNode{
	int child;	//	孩子结点下标
	struct CTNode* next;
}*ChildPtr;

// 双亲结点
typedef struct PCTBox{
	TElemType data;
	ChildPtr firstchild;	// 孩子链表头指针
	int parent;	//	双亲位置域
}PCTBox;

// 树结构
typedef struct PCTree{
	PCTBox nodes[MAX_TREE_SIZE];
	int r,n;	//记录根节点的下标位置和结点个数
}PCTree;

#endif