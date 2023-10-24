#ifndef __BSTREE_H__
#define __BSTREE_H__

typedef int KeyType;
typedef int InfoType;

typedef struct{
	KeyType key;	//	�ؼ�����
	InfoType otherinfo;	//	����������
}ElemType;

typedef struct BSTNode{
	ElemType Data;	//	������
	struct BSTNode *lch,*rch;	//	���Һ���ָ��
}BSTNode,*BSTree;	

//	�������������ң�����Ŀ����ָ��
BSTree SearchBST(BSTree T,KeyType Key);

#endif
