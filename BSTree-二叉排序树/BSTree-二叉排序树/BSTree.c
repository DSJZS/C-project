#define _CRT_SECURE_NO_WARNINGS 1

#include "BSTree.h"

BSTree SearchBST(BSTree T,KeyType Key)
{
	if((!T) || (Key == T->Data.key))
		return T;
	else if(Key < T->Data.key)
		SearchBST(T->lch,Key);	//	���������м�������
	else 
		SearchBST(T->rch,Key);	//	���������м�������
}