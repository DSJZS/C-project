#ifndef __ADJLIST_H__
#define __ADJLIST_H__

#define MVNum 100

#include <stdio.h>
#include <stdlib.h>

typedef char VerTexType;
typedef int OtherInfo;

typedef struct ArcNode{
	int adjvex;	//	该边所指向的顶点的位置
	struct ArcNode* nextarc;	//	指向下一条边的指针
	OtherInfo info;	//	和边相关的信息
}ArcNode;

typedef struct VNode{
	VerTexType data;	//	顶点信息
	ArcNode* fistarc;	//	指向第一条依附该顶点的边的指针
}VNode,AdjList[MVNum];	//	AdjList	代表领接表类型

typedef struct ALGraph{
	AdjList vertices;	//	vertices - vertex的复数	
	int vexnum,arcnum;	//	图当前顶点数和边数
}ALGraph;

//	创建无向网
int CreateUDN(ALGraph* G);

#endif