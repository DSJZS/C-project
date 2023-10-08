#ifndef __BILINKLIST_H__
#define __BILINKLIST_H__

#include <stdlib.h>

typedef char TElemType; 

typedef enum{
	Link,
	Thread
}PointerTag;

// ����������
typedef struct BiNode{
	TElemType data;
	struct BiNode *lchild,*rchild;	// ���Һ���ָ��
	PointerTag ltag,rtag;	// ���ұ�ʶ
}BiNode,*BiTree;


// �������������,�Ա������Ľ����visit��������(visitΪ��ʱ������)�����ر����˼������
int PreOrderTraverse(BiTree T, void(*visit)(TElemType*));

// �������������,�Ա������Ľ����visit��������(visitΪ��ʱ������)�����ر����˼������
int InOrderTraverse(BiTree T, void(*visit)(TElemType*));
// �����������������,�Ա������Ľ����visit��������(visitΪ��ʱ������)�����ر����˼������
int InOrderThraverse_Thr(BiTree T, void(*visit)(TElemType*));

// �������������,�Ա������Ľ����visit��������(visitΪ��ʱ������)�����ر����˼������
int PostOrderTraverse(BiTree T, void(*visit)(TElemType*));

// ��α���,�Ա������Ľ����visit��������(visitΪ��ʱ������)�����ر����˼������
int LevelOrder(BiTree T, void(*visit)(TElemType*));

// �����������д���������
// input Ϊ�Զ������뺯��
// delim Ϊ�жϿռ��ϵĺ���������1��ʾ�ռ���
int CreateBiTree(BiTree* T, void(*input)(TElemType* const), int(*delim)(const TElemType* const));

// ���ƶ�����
int CopyTree(BiTree T,BiTree* NewT);

// ������������
int TreeDepth(BiTree T);

// ���������Ҷ�ӽ�����
int LeafCount(BiTree T);

// ���������������
int TNodeCount(BiTree T);

//  ͨ�������������������������,����������ͷ���
int InOrderThread_Head(BiTree *h, BiTree T);

#endif