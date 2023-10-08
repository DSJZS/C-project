#ifndef __CSTREE_H__
#define __CSTREE_H__

typedef int TElemType;

typedef struct CSNode{
	TElemType data;
	struct CSNode *firstchild,*nextsibling;
}CSNode,*CSTree;


#endif