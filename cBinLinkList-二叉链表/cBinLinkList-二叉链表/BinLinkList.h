#ifndef __BILINKLIST_H__
#define __BILINKLIST_H__

#include <stdlib.h>

typedef char TElemType; 

typedef enum{
	Link,
	Thread
}PointerTag;

// 线索二叉树
typedef struct BiNode{
	TElemType data;
	struct BiNode *lchild,*rchild;	// 左右孩子指针
	PointerTag ltag,rtag;	// 左右标识
}BiNode,*BiTree;


// 先序遍历二叉树,对遍历到的结点用visit函数访问(visit为空时不访问)，返回遍历了几个结点
int PreOrderTraverse(BiTree T, void(*visit)(TElemType*));

// 中序遍历二叉树,对遍历到的结点用visit函数访问(visit为空时不访问)，返回遍历了几个结点
int InOrderTraverse(BiTree T, void(*visit)(TElemType*));
// 中序遍历线索二叉树,对遍历到的结点用visit函数访问(visit为空时不访问)，返回遍历了几个结点
int InOrderThraverse_Thr(BiTree T, void(*visit)(TElemType*));

// 后序遍历二叉树,对遍历到的结点用visit函数访问(visit为空时不访问)，返回遍历了几个结点
int PostOrderTraverse(BiTree T, void(*visit)(TElemType*));

// 层次遍历,对遍历到的结点用visit函数访问(visit为空时不访问)，返回遍历了几个结点
int LevelOrder(BiTree T, void(*visit)(TElemType*));

// 根据先序序列创建二叉树
// input 为自定义输入函数
// delim 为判断空集合的函数，返回1表示空集合
int CreateBiTree(BiTree* T, void(*input)(TElemType* const), int(*delim)(const TElemType* const));

// 复制二叉树
int CopyTree(BiTree T,BiTree* NewT);

// 计算二叉树深度
int TreeDepth(BiTree T);

// 计算二叉树叶子结点个数
int LeafCount(BiTree T);

// 计算二叉树结点个数
int TNodeCount(BiTree T);

//  通过中序遍历中序线索化二叉树,并建立建立头结点
int InOrderThread_Head(BiTree *h, BiTree T);

#endif