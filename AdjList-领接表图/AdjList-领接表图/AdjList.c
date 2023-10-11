#define _CRT_SECURE_NO_WARNINGS 1

#include "AdjList.h"

static int LocateVex(ALGraph* G, VerTexType v)
{
	int i = 0;
	for(i=0;i<G->vexnum;++i)
	{
		if(v == G->vertices[i].data)
			return i;
	}
	return -1;
}

int CreateUDN(ALGraph* G)
{
	int i = 0;	//	循环计数变量
	scanf("%d %d", &(G->vexnum),&(G->arcnum));	//	输入顶点数和边数

	//	输入结点构造表头结点表
	for(i=0;i<G->vexnum;++i)
	{
		scanf("%d", &(G->vertices[i].data));
		G->vertices[i].fistarc = NULL;	//	初始化表头结点指针域
	}

	for(i=0;i<G->arcnum;i++)
	{
		int v1=0,v2=0;
		int m=0,n=0;
		ArcNode *p1 = NULL,*p2 = NULL;
		scanf("%d %d",&v1,&v2);
		m = LocateVex(G,v1);
		n = LocateVex(G,v2);

		p1 = (ArcNode*)malloc(sizeof(ArcNode));
		if(!p1)
			return 0;
		p1->adjvex = n;
		p1->nextarc = G->vertices[m].fistarc;
		G->vertices[m].fistarc = p1;

		p2 = (ArcNode*)malloc(sizeof(ArcNode));
		if(!p2)
			return 0;
		p2->adjvex = m;
		p2->nextarc = G->vertices[n].fistarc;
		G->vertices[n].fistarc = p1;
	}

	return 1;
}