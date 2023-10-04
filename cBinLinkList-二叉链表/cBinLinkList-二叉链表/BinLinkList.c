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
	BiNode* r = NULL;
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
			if( p->rchild != r || p->rchild )
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