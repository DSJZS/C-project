#ifndef __PCTREE_H__
#define __PCTREE_H__

#define MAX_TREE_SIZE 100
typedef int TElemType;

// ���ӽ��
typedef struct CTNode{
	int child;	//	���ӽ���±�
	struct CTNode* next;
}*ChildPtr;

// ˫�׽��
typedef struct PCTBox{
	TElemType data;
	ChildPtr firstchild;	// ��������ͷָ��
	int parent;	//	˫��λ����
}PCTBox;

// ���ṹ
typedef struct PCTree{
	PCTBox nodes[MAX_TREE_SIZE];
	int r,n;	//��¼���ڵ���±�λ�úͽ�����
}PCTree;

#endif