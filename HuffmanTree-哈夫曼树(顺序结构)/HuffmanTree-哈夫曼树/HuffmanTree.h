#ifndef __HUFFMANTREE_H__
#define __HUFFMANTREE_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// ��������(˳��ṹ)
// �±��� 0 ��ʼ
typedef struct HTNode{
	int weight;	//	Ȩ��
	int parent,lch,rch;	//	˫�ף����Һ����±�
}HTNode,*HuffmanTree;

typedef char** HuffmanCode;	// ����ָ���Ź����������ַ������������Ԫ��

// �����������
int CreateHuffmanTree(HuffmanTree* HT,int n);
// ���ɹ���������
void CreateHuffmanCode(HuffmanTree HT,HuffmanCode* HC , int n);



#endif
