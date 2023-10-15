#define _CRT_SECURE_NO_WARNINGS 1

#include "AMGraph.h"

int main()
{
	AMGraph G;
	CreateUDN(&G);
	PrintGraph(&G); 
	MiniSpanTree_Prim(&G,'A');

	return 0;
}