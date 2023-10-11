#ifndef __AMGRAPH_H__
#define __AMGRAPH_H__

/*	����Ӿ���ͼΪ������	*/

#define MVNum 100	//	������󶥵��� max vertex num
#define MaxInt 10086	//	��ʾ����ֵ

#include <stdio.h>

typedef char VerTexType;	//	���ö������������
typedef int ArcType;	//	���ñߵ���������

typedef struct AMGraph{
	VerTexType vexs[MVNum];	//	�����
	ArcType arcs[MVNum][MVNum];	//	��Ӿ���
	int vexnum,arcnum;	//	ͼ�ĵ�ǰ�������͵�ǰ����
}AMGraph;	//	Adjacency Matrix Graph


//	����������
int CreateUDN(AMGraph* G);
#endif