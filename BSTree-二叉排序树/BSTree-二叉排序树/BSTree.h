#ifndef __BSTREE_H__
#define __BSTREE_H__

typedef int KeyType;
typedef int InfoType;

typedef struct{
	KeyType key;	//	关键字项
	InfoType otherinfo;	//	其它数据域
}ElemType;

typedef struct BSTNode{
	ElemType Data;	//	数据域
	struct BSTNode *lch,*rch;	//	左右孩子指针
}BSTNode,*BSTree;	

//	二叉排序树查找，返回目标结点指针
BSTree SearchBST(BSTree T,KeyType Key);

#endif
