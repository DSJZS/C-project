#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include "BinLinkList.h"

int main()
{
	BiTree bt = NULL;

	printf("%d\n", PreOrderTraverse(bt,NULL));

	return 0;
}