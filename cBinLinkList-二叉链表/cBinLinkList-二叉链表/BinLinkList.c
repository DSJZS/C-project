#define _CRT_SECURE_NO_WARNINGS 1

#include "BinLinkList.h"
#include "cLinkStack.h"
#include "cLinkQueue.h"

// 递归版
/*
int PreOrderTraverse(BiTree T, void(*visit)(TElemType*))
{
	if(!T)	// 判断是否为空树
		return 0;
	if(visit)	// 判断visit指针是否为空
		visit( &(T->data) );	//	访问根结点

	//	访问左右子树，同时返回遍历的结点数
	return ( PreOrderTraverse(T->lchild,visit) + PreOrderTraverse(T->rchild,visit) + 1);
}
*/
// 非递归版
int PreOrderTraverse(BiTree T, void(*visit)(TElemType*))
{
	BiTree p = T;
	int count = 0;
	LinkStack S;
	InitStack_LS(&S);

	while(p || !IsEmpty_LS(S))
	{
		if(p)
		{
			visit( &(p->data) );
			++count;
			Push_LS(&S,p);
			p = p->lchild;
		}
		else
		{
			Pop_LS(&S,&p);
			p = p->rchild;
		}
	}
	return count;
}

// 递归版
/* 
int InOrderTraverse(BiTree T, void(*visit)(TElemType*))
{
	int count = 0;
	if(!T)	// 判断是否为空树
		return 0;

	// 访问左子树
	count += InOrderTraverse(T->lchild,visit);

	// 访问根结点
	if(visit)	// 判断visit指针是否为空
		visit( &(T->data) );	//	访问根结点
	++count;

	// 访问右子树
	count += InOrderTraverse(T->rchild,visit);

	//	返回访问的结点数
	return count;
}
*/
// 非递归版
int InOrderTraverse(BiTree T, void(*visit)(TElemType*))
{
	BiTree p = T;

	int count = 0;
	LinkStack S;
	InitStack_LS(&S);

	while(p || !IsEmpty_LS(S))
	{
		if(p)
		{
			Push_LS(&S,p);
			p = p->lchild;
		}
		else
		{
			Pop_LS(&S,&p);
			if(visit)
				visit( &(p->data) );
			++count;
			p = p->rchild;
		}
	}
	return count;
}

int InOrderThraverse_Thr(BiTree T, void(*visit)(TElemType*))
{
	BiTree p = T->lchild;
	int count = 0;

	while(p != T)
	{
		while(p->ltag == Link)	// 找到中序序列的第一个结点
		{
			p = p->lchild;
		}
		visit( &(p->data) );
		++count;
		while((p->rtag == Thread) && (p->rchild != T))	// 通过线索找到后继并访问
		{
			p = p->rchild;
			visit( &(p->data) );
			++count;
		}

		p = p->rchild;	// // 当前p结点的左子树和自身(根)访问完毕，于是进入右子树
	}

	return count;
}

// 递归版
/*
int PostOrderTraverse(BiTree T, void(*visit)(TElemType*))
{
	int count = 0;
	if(!T)	// 判断是否为空树
		return 0;

	// 访问左子树
	count += InOrderTraverse(T->lchild,visit);

	// 访问右子树
	count += InOrderTraverse(T->rchild,visit);

	// 访问根结点
	if(visit)	// 判断visit指针是否为空
		visit( &(T->data) );	//	访问根结点
	++count;

	//	返回访问的结点数
	return count;
}
*/


// 非递归版
int PostOrderTraverse(BiTree T, void(*visit)(TElemType*))
{
	BiTree p = T;
	BiNode* r = NULL;	//	记住访问过的上一个结点
	int count = 0;
	LinkStack S;
	InitStack_LS(&S);

	while(p || !IsEmpty_LS(S))
	{
		if(p)
		{
			Push_LS(&S,p);
			p = p->lchild;
		}
		else
		{
			GetTop_LS(S,&p);
			if( p->rchild != r && p->rchild )
			{
				p = p->rchild;
			}
			else
			{
				Pop_LS(&S,&p);

				if(visit)
					visit( &(p->data) );
				++count;

				r = p;
				p = NULL;
			}
		}
	}

	return 1; 
}

int LevelOrder(BiTree T, void(*visit)(TElemType*))
{
	BiTree p = NULL;
	int count = 0;
	LinkQueue Q;
	InitQueue_LQ(&Q);

	EnQueue_LQ(&Q,T);	// 入队
	while(!IsEmpty_LQ(&Q))
	{
		DeQueue_LQ(&Q,&p);	// 出队
		visit( &(p->data) );
		++count;

		if(p->lchild)	// 判断有没有左孩子
		{
			EnQueue_LQ(&Q,p->lchild);
		}
		if(p->rchild)	// 判断有没有右孩子
		{
			EnQueue_LQ(&Q,p->rchild);
		}
	}
	return count;
}

int CreateBiTree(BiTree* T, void(*input)(TElemType* const), int(*delim)(const TElemType* const))
{
	TElemType te = 0;
	input(&te);

	if(delim(&te))
	{	
		*T = NULL;
	}
	else
	{
		if( !((*T) = (BiNode*)malloc(sizeof(BiNode)) ) )
			return 0;
		(*T)->data = te;
		CreateBiTree(&((*T)->lchild),input,delim);
		CreateBiTree(&((*T)->rchild),input,delim);
	}
	return 1;
}

int CopyTree(BiTree T,BiTree* NewT)
{
	if(!T)
	{
		*NewT = NULL;
		return 0;
	}
	(*NewT) = (BiNode*)malloc(sizeof(BiNode));
	(*NewT)->data = T->data;

	return CopyTree(T->lchild, &((*NewT)->lchild) )+ CopyTree(T->rchild, &((*NewT)->rchild) )+1;
}

int TreeDepth(BiTree T)
{
	int m = 0;
	int n = 0;
	if(!T)
		return 0;

	m = TreeDepth(T->lchild);
	n = TreeDepth(T->rchild);

	if(m>n)
		return (m+1);
	else
		return (n+1);
}

int LeafCount(BiTree T)
{
	if(!T)
		return 0;
	if(  !(T->lchild)  &&  !(T->rchild)  )
		return 1;

	return (  LeafCount(T->lchild) + LeafCount(T->rchild)  );
}

int TNodeCount(BiTree T)
{
	if(!T)
		return 0;
	return (  TNodeCount(T->lchild) + TNodeCount(T->rchild) + 1  );
}

static BiTree pre = NULL;	// 记载着二叉树中上一个访问的节点

static void InThreading(BiTree T)
{
	if(T)
	{	
		InThreading(T->lchild);	// 线索化左子树

		if(!T->lchild)
		{
			T->ltag = Thread;
			T->lchild = pre;
		}
		else
		{
			T->ltag = Link;
		}

		if(!pre->rchild)
		{
			pre->rtag = Thread;
			pre->rchild = T;
		}
		else
		{
			pre->rtag = Link;
		}

		pre = T;

		InThreading(T->rchild);	// 线索化右子树
	}
	
}

int InOrderThread_Head(BiTree *h, BiTree T)
{
	(*h) = (BiNode*)malloc(sizeof(BiNode));
	if( (*h) == NULL )
		return 0;

	(*h)->rchild = (*h);
	(*h)->rtag = Link;

	if(!T)
	{
		(*h)->lchild = (*h);
		(*h)->ltag = Link;
	}
	else
	{
		pre = (*h);	// 便于序列首结点指向头结点
		(*h)->ltag = Link;
		(*h)->lchild = T;
		
		InThreading(T);

		pre->rtag = Thread;	// 使序列尾结点指向头结点
		pre->rchild = (*h);
		(*h)->rchild = pre;	// 使头结点指向序列尾结点
	}
	return 1;
}