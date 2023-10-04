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