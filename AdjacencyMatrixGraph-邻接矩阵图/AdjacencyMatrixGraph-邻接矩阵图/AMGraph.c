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
	printf("输入顶点数\n");
	scanf("%d", &(G->vexnum));

	//	输入顶点的信息
	printf("输入边数\n");
	scanf("%d", &(G->arcnum));
	getchar();
	printf("输入顶点元素(无需空格隔开)：");
	scanf("%s", G->vexs );
	getchar();

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
		printf("输入第 %d 条边的信息\n",i+1);
		scanf("%c %c %d",&v1,&v2,&w);
		getchar();
		m = LocateVex(G,v1);
		n = LocateVex(G,v2);

		if((m==-1) || (n==-1))
		{
			printf("下标输入错误\n");
			return 0;
		}
		
		G->arcs[m][n] = G->arcs[n][m] = w;
	}


	return 1;
}

//	记录遍历过的顶点
static int visited[MVNum] = {0};

static void DFS(AMGraph* G,int v)
{
	
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
void DFSTraverse(AMGraph* G)
{
	int i = 0;
	for(i=0;i<G->vexnum;++i)
	{
		visited[i] = 0;	//初始化"标志"数组为0，代表未访问
 	}

	for(i=0;i<G->vexnum;++i)	//	防止非连通图的情况，检查每个顶点是否访问过
	{
		if(visited[i] != 0)
			DFS(G,i);
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
void BFSTraverse(AMGraph* G)
{
	int i = 0;
	for(i=0;i<G->vexnum;++i)
	{
		visited[i] = 0;	//初始化"标志"数组为0，代表未访问
	}

	for(i=0;i<G->vexnum;++i)	//	防止非连通图的情况，检查每个顶点是否访问过
	{
		if(visited[i] != 0)
			DFS(G,i);
	}
}

static int minimal(AMGraph* G,ShortEdge* shortedge)
{
	int i = 0;
	int min = MaxInt;
	int loc = 0;

	for(i=1;i<G->vexnum;++i)
	{
		if( (min>shortedge[i].lowcost) && (shortedge[i].lowcost != 0) )
		{
			min = shortedge[i].lowcost;
			loc = i;
		}
	}
	return loc;
}
void MiniSpanTree_Prim(AMGraph* G,VerTexType start)
{
	int i=0,j=0;	//	循环遍历
	int k = 0;	//	记录目标顶点的下标

	//	初始化
	ShortEdge shortedge[MVNum];
	k = LocateVex(G,start);	//	寻找起始结点下标
	for(i=0;i<G->vexnum;++i)	
	{
		shortedge[i].adjvex = start;
		shortedge[i].lowcost = G->arcs[k][i];
	}
	shortedge[i].lowcost = 0;	//	将起始结点放入 U集合

	//	处理所有结点，根据公式，最小生成树有 G->vexnum-1 条边
	for(i=0;i<G->vexnum-1;++i)
	{
		k = minimal(G,shortedge);
		printf("%c->%c : w=%d\n", shortedge[k].adjvex,G->vexs[k],shortedge[k].lowcost);
		shortedge[k].lowcost = 0;	//	将结点放入 U集合

		//	更新shortedge数组，判断U集合加入新结点后，V-U和U中可能出现的最短路径
		//	即判断新加的 Vk 结点到V-U中每个结点的权重是否比 Vs 结点小
		//	如果发现，记录那个结点到U集合的最短边邻接点应为 Vk
		for(j=0;j<G->vexnum;++j)
		{
			if(shortedge[j].lowcost > G->arcs[k][j])
			{
				shortedge[j].adjvex = G->vexs[k];
				shortedge[j].lowcost = G->arcs[k][j];
			}
		}
	}
}

void PrintGraph(AMGraph* G)
{
	int i,j;
	printf("\n-------------------------------");
	printf("\n 邻接矩阵：\n\n"); 	

	printf("\t ");
	for(i=0;i<G->vexnum;i++)
		printf("\t%c",G->vexs[i]);
	printf("\n");

	for(i=0;i<G->vexnum;i++)
	{
		printf("\t%c",G->vexs[i]);

		for(j=0;j<G->vexnum;j++)
		{

			if(G->arcs[i][j]==MaxInt)
				printf("\t∞");
			else printf("\t%d",G->arcs[i][j]);
		}
		printf("\n");
	}

}
