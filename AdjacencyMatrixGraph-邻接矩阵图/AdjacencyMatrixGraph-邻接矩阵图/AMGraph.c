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
	int i = 0;	//	ѭ����������

	//	���붥�����ͱ���
	printf("���붥����\n");
	scanf("%d", &(G->vexnum));

	//	���붥�����Ϣ
	printf("�������\n");
	scanf("%d", &(G->arcnum));
	getchar();
	printf("���붥��Ԫ��(����ո����)��");
	scanf("%s", G->vexs );
	getchar();

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
	for(i=0;i<G->arcnum;++i)
	{
		char v1,v2;
		int m,n,w;
		printf("����� %d ���ߵ���Ϣ\n",i+1);
		scanf("%c %c %d",&v1,&v2,&w);
		getchar();
		m = LocateVex(G,v1);
		n = LocateVex(G,v2);

		if((m==-1) || (n==-1))
		{
			printf("�±��������\n");
			return 0;
		}
		
		G->arcs[m][n] = G->arcs[n][m] = w;
	}


	return 1;
}

//	��¼�������Ķ���
static int visited[MVNum] = {0};

static void DFS(AMGraph* G,int v)
{
	
	int w = 0;
	printf("%d", v);
	visited[v] = 1;

	for(w=0;w<G->vexnum;++w)
	{
		//	w �� v ���ڽӵ㣬�� w û�б����ʹ�
		if((G->arcs[v][w] != 0) && (!visited[w]))
			DFS(G,w);
	}
}
void DFSTraverse(AMGraph* G)
{
	int i = 0;
	for(i=0;i<G->vexnum;++i)
	{
		visited[i] = 0;	//��ʼ��"��־"����Ϊ0������δ����
 	}

	for(i=0;i<G->vexnum;++i)	//	��ֹ����ͨͼ����������ÿ�������Ƿ���ʹ�
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
		visited[i] = 0;	//��ʼ��"��־"����Ϊ0������δ����
	}

	for(i=0;i<G->vexnum;++i)	//	��ֹ����ͨͼ����������ÿ�������Ƿ���ʹ�
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
	int i=0,j=0;	//	ѭ������
	int k = 0;	//	��¼Ŀ�궥����±�

	//	��ʼ��
	ShortEdge shortedge[MVNum];
	k = LocateVex(G,start);	//	Ѱ����ʼ����±�
	for(i=0;i<G->vexnum;++i)	
	{
		shortedge[i].adjvex = start;
		shortedge[i].lowcost = G->arcs[k][i];
	}
	shortedge[i].lowcost = 0;	//	����ʼ������ U����

	//	�������н�㣬���ݹ�ʽ����С�������� G->vexnum-1 ����
	for(i=0;i<G->vexnum-1;++i)
	{
		k = minimal(G,shortedge);
		printf("%c->%c : w=%d\n", shortedge[k].adjvex,G->vexs[k],shortedge[k].lowcost);
		shortedge[k].lowcost = 0;	//	�������� U����

		//	����shortedge���飬�ж�U���ϼ����½���V-U��U�п��ܳ��ֵ����·��
		//	���ж��¼ӵ� Vk ��㵽V-U��ÿ������Ȩ���Ƿ�� Vs ���С
		//	������֣���¼�Ǹ���㵽U���ϵ���̱��ڽӵ�ӦΪ Vk
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
	printf("\n �ڽӾ���\n\n"); 	

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
				printf("\t��");
			else printf("\t%d",G->arcs[i][j]);
		}
		printf("\n");
	}

}
