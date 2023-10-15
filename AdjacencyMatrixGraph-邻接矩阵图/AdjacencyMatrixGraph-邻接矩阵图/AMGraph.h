#ifndef __AMGRAPH_H__
#define __AMGRAPH_H__

/*	����Ӿ���ͼΪ������	*/

#define MVNum 100	//	������󶥵��� max vertex num
#define MaxInt 10086	//	��ʾ����ֵ

#include <stdio.h>
#include "cLinkQueue.h"

typedef char VerTexType;	//	���ö������������
typedef int ArcType;	//	���ñߵ���������

typedef struct//���·������ṹ��(��ѡ��̱�) 
{
	VerTexType adjvex;//��ѡ��̱ߵ��ڽӵ� 
	int lowcost;//��ѡ��̱ߵ�Ȩֵ 
}ShortEdge;


typedef struct AMGraph{	//	��Ӿ���ͼ
	VerTexType vexs[MVNum];	//	�����
	ArcType arcs[MVNum][MVNum];	//	��Ӿ���
	int vexnum,arcnum;	//	ͼ�ĵ�ǰ�������͵�ǰ����
}AMGraph;	//	Adjacency Matrix Graph


//	����������
int CreateUDN(AMGraph* G);

//	ͼ�������������
void DFSTraverse(AMGraph* G);

//	ͼ�Ĺ����������
void BFSTraverse(AMGraph* G);

//	Prim�㷨Ѱ����С������
void MiniSpanTree_Prim(AMGraph* G,VerTexType start);

//��ӡ��Ӿ���
void PrintGraph(AMGraph* G);

#endif