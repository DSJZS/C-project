#ifndef __TRILINKLIST_H__
#define __TRILINKLIST_H__

typedef int TElemType;

typedef struct TriNode{
	TElemType data;
	struct TriNode *lchild,*rchild,*parent;		// ���Һ��Ӻ�˫��ָ��
}TriNode,*TriTree;



#endif