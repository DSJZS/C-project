#define _CRT_SECURE_NO_WARNINGS 1

#include "BinLinkList.h"
#include "cLinkStack.h"
#include "cLinkQueue.h"

// �ݹ��
/*
int PreOrderTraverse(BiTree T, void(*visit)(TElemType*))
{
	if(!T)	// �ж��Ƿ�Ϊ����
		return 0;
	if(visit)	// �ж�visitָ���Ƿ�Ϊ��
		visit( &(T->data) );	//	���ʸ����

	//	��������������ͬʱ���ر����Ľ����
	return ( PreOrderTraverse(T->lchild,visit) + PreOrderTraverse(T->rchild,visit) + 1);
}
*/
// �ǵݹ��
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

// �ݹ��
/* 
int InOrderTraverse(BiTree T, void(*visit)(TElemType*))
{
	int count = 0;
	if(!T)	// �ж��Ƿ�Ϊ����
		return 0;

	// ����������
	count += InOrderTraverse(T->lchild,visit);

	// ���ʸ����
	if(visit)	// �ж�visitָ���Ƿ�Ϊ��
		visit( &(T->data) );	//	���ʸ����
	++count;

	// ����������
	count += InOrderTraverse(T->rchild,visit);

	//	���ط��ʵĽ����
	return count;
}
*/
// �ǵݹ��
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
		while(p->ltag == Link)	// �ҵ��������еĵ�һ�����
		{
			p = p->lchild;
		}
		visit( &(p->data) );
		++count;
		while((p->rtag == Thread) && (p->rchild != T))	// ͨ�������ҵ���̲�����
		{
			p = p->rchild;
			visit( &(p->data) );
			++count;
		}

		p = p->rchild;	// // ��ǰp����������������(��)������ϣ����ǽ���������
	}

	return count;
}

// �ݹ��
/*
int PostOrderTraverse(BiTree T, void(*visit)(TElemType*))
{
	int count = 0;
	if(!T)	// �ж��Ƿ�Ϊ����
		return 0;

	// ����������
	count += InOrderTraverse(T->lchild,visit);

	// ����������
	count += InOrderTraverse(T->rchild,visit);

	// ���ʸ����
	if(visit)	// �ж�visitָ���Ƿ�Ϊ��
		visit( &(T->data) );	//	���ʸ����
	++count;

	//	���ط��ʵĽ����
	return count;
}
*/


// �ǵݹ��
int PostOrderTraverse(BiTree T, void(*visit)(TElemType*))
{
	BiTree p = T;
	BiNode* r = NULL;	//	��ס���ʹ�����һ�����
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

	EnQueue_LQ(&Q,T);	// ���
	while(!IsEmpty_LQ(&Q))
	{
		DeQueue_LQ(&Q,&p);	// ����
		visit( &(p->data) );
		++count;

		if(p->lchild)	// �ж���û������
		{
			EnQueue_LQ(&Q,p->lchild);
		}
		if(p->rchild)	// �ж���û���Һ���
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

static BiTree pre = NULL;	// �����Ŷ���������һ�����ʵĽڵ�

static void InThreading(BiTree T)
{
	if(T)
	{	
		InThreading(T->lchild);	// ������������

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

		InThreading(T->rchild);	// ������������
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
		pre = (*h);	// ���������׽��ָ��ͷ���
		(*h)->ltag = Link;
		(*h)->lchild = T;
		
		InThreading(T);

		pre->rtag = Thread;	// ʹ����β���ָ��ͷ���
		pre->rchild = (*h);
		(*h)->rchild = pre;	// ʹͷ���ָ������β���
	}
	return 1;
}