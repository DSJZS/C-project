#ifndef __PTREE_H__
#define __PTREE_H__

#define MAX_TREE_SIZE 100

typedef int TElemType;

typedef struct PTNode{
	TElemType data;
	int parent;	//	双亲位置域
}PTNode;

typedef struct PTree{
	PTNode nodes[MAX_TREE_SIZE];
	int r,n;	//记录根节点的下标位置和结点个数
}PTree;

#endif