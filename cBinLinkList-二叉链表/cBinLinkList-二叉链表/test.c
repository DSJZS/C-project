#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include "BinLinkList.h"

void visit(TElemType* te)
{
	printf("%c\n", *te);
}

void input(TElemType* const te)
{
	scanf("%c",te);
	while('\n' != getchar());
}

int delim(const TElemType* const te)
{
	if(*te == '#')
		return 1;
	else
		return 0;
}

int main()
{
	BiTree bt1 = NULL;
	BiTree bt2 = NULL;

	CreateBiTree(&bt1,input,delim);
	CopyTree(bt1,&bt2);
	InOrderThread_Head(&bt2,bt2);

	printf("\n");

	printf("%d\n", InOrderThraverse_Thr(bt2,visit));
	//printf("%d\n", TreeDepth(bt2));
	//printf("%d\n", LeafCount(bt2));
	//printf("%d\n", TNodeCount(bt2));

	return 0;
}