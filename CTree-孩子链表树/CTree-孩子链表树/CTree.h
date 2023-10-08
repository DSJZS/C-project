#ifndef __CTREE_H__
#define __CTREE_H__

#define MAX_TREE_SIZE 100
typedef int TElemType;

// ���ӽ��
typedef struct CTNode{
	int child;	//	���ӽ���±�
	struct CTNode* next;
}*ChildPtr;

// ˫�׽��
typedef struct CTBox{
	TElemType data;
	ChildPtr firstchild;	// ��������ͷָ��
}CTBox;

// ���ṹ
typedef struct CTree{
	CTBox nodes[MAX_TREE_SIZE];
	int r,n;	//��¼���ڵ���±�λ�úͽ�����
}CTree;


#endif