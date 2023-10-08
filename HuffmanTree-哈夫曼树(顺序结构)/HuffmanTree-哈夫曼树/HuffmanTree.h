#ifndef __HUFFMANTREE_H__
#define __HUFFMANTREE_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// 哈夫曼树(顺序结构)
// 下标由 0 开始
typedef struct HTNode{
	int weight;	//	权重
	int parent,lch,rch;	//	双亲，左右孩子下标
}HTNode,*HuffmanTree;

typedef char** HuffmanCode;	// 用于指向存放哈夫曼编码字符串的数组的首元素

// 构造哈夫曼树
int CreateHuffmanTree(HuffmanTree* HT,int n);
// 生成哈夫曼编码
void CreateHuffmanCode(HuffmanTree HT,HuffmanCode* HC , int n);



#endif
