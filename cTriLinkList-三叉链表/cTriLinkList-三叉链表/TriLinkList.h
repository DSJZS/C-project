#ifndef __TRILINKLIST_H__
#define __TRILINKLIST_H__

typedef int TElemType;

typedef struct TriNode{
	TElemType data;
	struct TriNode *lchild,*rchild,*parent;		// ×óÓÒº¢×ÓºÍË«Ç×Ö¸Õë
}TriNode,*TriTree;



#endif