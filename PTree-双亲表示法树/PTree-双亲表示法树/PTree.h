#ifndef __PTREE_H__
#define __PTREE_H__

#define MAX_TREE_SIZE 100

typedef int TElemType;

typedef struct PTNode{
	TElemType data;
	int parent;	//	˫��λ����
}PTNode;

typedef struct PTree{
	PTNode nodes[MAX_TREE_SIZE];
	int r,n;	//��¼���ڵ���±�λ�úͽ�����
}PTree;

#endif