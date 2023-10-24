#define _CRT_SECURE_NO_WARNINGS 1

#include "BSTree.h"

BSTree SearchBST(BSTree T,KeyType Key)
{
	if((!T) || (Key == T->Data.key))
		return T;
	else if(Key < T->Data.key)
		SearchBST(T->lch,Key);	//	在左子树中继续查找
	else 
		SearchBST(T->rch,Key);	//	在右子树中继续查找
}