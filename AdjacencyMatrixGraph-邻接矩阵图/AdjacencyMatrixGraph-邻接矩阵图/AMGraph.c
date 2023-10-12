#define _CRT_SECURE_NO_WARNINGS 1

#include "AMGraph.h"

static int LocateVex(AMGraph* G, VerTexType v)
{
	int i = 0;
	for(i = 0 ; i < (G->vexnum); ++i )
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
	for(i=0;i<G->arcnum;++i)
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

void DFS(AMGraph* G,int v)
{
	int visited[MVNum] = {0};
	int w = 0;
	printf("%d", v);
	visited[v] = 1;

	for(w=0;w<G->vexnum;++w)
	{
		//	w 是 v 的邻接点，且 w 没有被访问过
		if((G->arcs[v][w] != 0) && (!visited[w]))
			DFS(G,w);
	}
}

static int FirstAdjVex(AMGraph* G,int u)
{
	int i = 0;
	for(i=0;i<G->vexnum;++i)
	{
		if(G->arcs[u][i] != 0)
			return i;
	}
	return -1;
}
static int NextAdjVex(AMGraph* G,int u,int w)
{
	int i = 0;
	for(i=w;i<G->vexnum;++i)
	{
		if(G->arcs[u][i] != 0)
			return i;
	}
	return -1;
}

void BFS(AMGraph* G,int v)
{

	int visited[MVNum] = {0};
	int w = 0;
	LinkQueue Q;
	printf("%d", v);
	visited[v] = 1;

	InitQueue_LQ(&Q);
	EnQueue_LQ(&Q,v);
	while(!IsEmpty_LQ(&Q))
	{
		int u = 0;
		DeQueue_LQ(&Q,&u);
		for(w=FirstAdjVex(G,u) ; w>= 0; w=NextAdjVex(G,u,w))
		{
			if(visited[w] != 0)
			{
				printf("%d", w);
				visited[w] = 1;
				EnQueue_LQ(&Q,w);
			}
		}
	}

}