#ifndef __BILINKLIST_H__
#define __BILINKLIST_H__

typedef int TElemType; 

typedef struct BiNode{
	TElemType data;
	struct BiNode *lchild,*rchild;	// ���Һ���ָ��
}BiNode,*BiTree;


#endif