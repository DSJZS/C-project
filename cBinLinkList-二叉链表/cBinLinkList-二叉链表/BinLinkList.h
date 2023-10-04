#ifndef __BILINKLIST_H__
#define __BILINKLIST_H__

#include <stdlib.h>

typedef int TElemType; 

typedef struct BiNode{
	TElemType data;
	struct BiNode *lchild,*rchild;	// ���Һ���ָ��
}BiNode,*BiTree;

// �������������,�Ա������Ľ����visit��������(visitΪ��ʱ������)�����ر����˼������
int PreOrderTraverse(BiTree T, void(*visit)(TElemType*));
// �������������,�Ա������Ľ����visit��������(visitΪ��ʱ������)�����ر����˼������
int InOrderTraverse(BiTree T, void(*visit)(TElemType*));
// �������������,�Ա������Ľ����visit��������(visitΪ��ʱ������)�����ر����˼������
int PostOrderTraverse(BiTree T, void(*visit)(TElemType*));

// ��α���,�Ա������Ľ����visit��������(visitΪ��ʱ������)�����ر����˼������
int LevelOrder(BiTree T, void(*visit)(TElemType*));

#endif