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

	while(p || IsEmpty_LS(S))
	{
		if(p)
		{
			visit( &(p->data) );
			++count;
			Push_LS(&S,*p);
			p = p->lchild;
		}
		else
		{
			Pop_LS(&S,p);
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
			Push_LS(&S,*p);
			p = p->lchild;
		}
		else
		{
			Pop_LS(&S,p);
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
	BiTree p = NULL;
	BiNode* r = NULL;
	int count = 0;
	LinkStack S;
	InitStack_LS(&S);

	while(p || IsEmpty_LS(S))
	{
		if(p)
		{
			Push_LS(&S,*p);
			p = p->lchild;
		}
		else
		{
			GetTop_LS(S,p);
			if(p != r || p->rchild )
			{
				p = p->rchild;
			}
			else
			{
				Pop_LS(&S,p);

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
	BiNode* r = NULL;
	LinkQueue Q;
	InitQueue_LQ(&Q);
	EnQueue_LQ(&Q,*T);

	while(IsEmp)
}