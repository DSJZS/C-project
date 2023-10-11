#ifndef __ADJLIST_H__
#define __ADJLIST_H__

#define MVNum 100

#include <stdio.h>
#include <stdlib.h>

typedef char VerTexType;
typedef int OtherInfo;

typedef struct ArcNode{
	int adjvex;	//	�ñ���ָ��Ķ����λ��
	struct ArcNode* nextarc;	//	ָ����һ���ߵ�ָ��
	OtherInfo info;	//	�ͱ���ص���Ϣ
}ArcNode;

typedef struct VNode{
	VerTexType data;	//	������Ϣ
	ArcNode* fistarc;	//	ָ���һ�������ö���ıߵ�ָ��
}VNode,AdjList[MVNum];	//	AdjList	������ӱ�����

typedef struct ALGraph{
	AdjList vertices;	//	vertices - vertex�ĸ���	
	int vexnum,arcnum;	//	ͼ��ǰ�������ͱ���
}ALGraph;

//	����������
int CreateUDN(ALGraph* G);

#endif