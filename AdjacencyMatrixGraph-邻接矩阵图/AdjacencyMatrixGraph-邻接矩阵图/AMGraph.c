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
	int i = 0;	//	ѭ����������

	//	���붥�����ͱ���
	scanf("%d %d", &(G->vexnum),&(G->arcnum));

	//	���붥�����Ϣ
	for(i=0;i<G->vexnum;i++)
	{
		scanf("%c", &(G->vexs[i]) );
	}

	//	��ʼ����Ӿ���
	for(i=0;i<G->vexnum;++i)
	{
		int j = 0;
		for(j=0;j<G->vexnum;++j)
		{
			G->arcs[i][j] = MaxInt;
		}
	}

	//	�����ڽӾ���
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