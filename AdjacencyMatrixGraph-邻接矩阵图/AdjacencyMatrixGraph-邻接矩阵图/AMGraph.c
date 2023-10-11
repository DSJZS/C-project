#define _CRT_SECURE_NO_WARNINGS 1

#include "AMGraph.h"

static int LocateVex(AMGraph* G, VerTexType v)
{
	int i = 0;
	for(i=0;i<G->vexnum;++i)
	{
		if(v == G->vexs[i])
			return i;
	}
	return -1;
}

int CreateUDN(AMGraph* G)
{
	int i = 0;	//	循环计数变量

	//	输入顶点数和边数
	scanf("%d %d", &(G->vexnum),&(G->arcnum));

	//	输入顶点的信息
	for(i=0;i<G->vexnum;i++)
	{
		scanf("%c", &(G->vexs[i]) );
	}

	//	初始化领接矩阵
	for(i=0;i<G->vexnum;++i)
	{
		int j = 0;
		for(j=0;j<G->vexnum;++j)
		{
			G->arcs[i][j] = MaxInt;
		}
	}

	//	构造邻接矩阵
	for(i<0;i<G->arcnum;++i)
	{
		char v1,v2;
		int m,n,w;
		scanf("%c %c %d",&v1,&v2,&w);
		m = LocateVex(G,v1);
		n = LocateVex(G,v2);
		G->arcs[m][n] = G->arcs[n][m] = w;
	}


	return 1;
}