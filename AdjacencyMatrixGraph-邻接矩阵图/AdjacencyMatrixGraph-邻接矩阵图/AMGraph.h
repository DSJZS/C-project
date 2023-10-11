#ifndef __AMGRAPH_H__
#define __AMGRAPH_H__

/*	该领接矩阵图为无向网	*/

#define MVNum 100	//	设置最大顶点数 max vertex num
#define MaxInt 10086	//	表示极大值

#include <stdio.h>

typedef char VerTexType;	//	设置顶点的数据类型
typedef int ArcType;	//	设置边的数据类型

typedef struct AMGraph{
	VerTexType vexs[MVNum];	//	顶点表
	ArcType arcs[MVNum][MVNum];	//	领接矩阵
	int vexnum,arcnum;	//	图的当前顶点数和当前边数
}AMGraph;	//	Adjacency Matrix Graph


//	构造无向网
int CreateUDN(AMGraph* G);
#endif