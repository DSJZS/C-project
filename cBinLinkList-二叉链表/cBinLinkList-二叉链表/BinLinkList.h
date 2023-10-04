#ifndef __BILINKLIST_H__
#define __BILINKLIST_H__

#include <stdlib.h>

typedef int TElemType; 

typedef struct BiNode{
	TElemType data;
	struct BiNode *lchild,*rchild;	// 左右孩子指针
}BiNode,*BiTree;

// 先序遍历二叉树,对遍历到的结点用visit函数访问(visit为空时不访问)，返回遍历了几个结点
int PreOrderTraverse(BiTree T, void(*visit)(TElemType*));
// 中序遍历二叉树,对遍历到的结点用visit函数访问(visit为空时不访问)，返回遍历了几个结点
int InOrderTraverse(BiTree T, void(*visit)(TElemType*));
// 后序遍历二叉树,对遍历到的结点用visit函数访问(visit为空时不访问)，返回遍历了几个结点
int PostOrderTraverse(BiTree T, void(*visit)(TElemType*));

// 层次遍历,对遍历到的结点用visit函数访问(visit为空时不访问)，返回遍历了几个结点
int LevelOrder(BiTree T, void(*visit)(TElemType*));

#endif