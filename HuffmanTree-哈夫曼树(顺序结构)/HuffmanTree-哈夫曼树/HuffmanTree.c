#define _CRT_SECURE_NO_WARNINGS 1

#include "HuffmanTree.h"

// 查找权重最小的两个树
static void Select(HuffmanTree HT,int n,int* s1,int* s2)
{
	int i = 0;
	*s1 = *s2 = -1;
	for(i=0;i<n;i++)
	{
		if((*s1 == -1)&&(HT[i].parent==-1))
		{
			*s1 = i;
		}
		else if((*s2 == -1)&&(HT[i].parent==-1))
		{
			*s2 = i;
		}
		else if(HT[i].parent==-1)
		{
				int m = HT[*s1].weight;
				int n = HT[*s2].weight;
				if( HT[i].weight < (m>n?m:n) )
				{
					if(m>n)
						*s1 = i;
					else
						*s2 = i;
				}
		}
	}
}

int CreateHuffmanTree(HuffmanTree* HT,int n)
{
	int m = 0;
	int i = 0;
	if(n < 1)	// 判断 n 是否合法
		return 0;

	m = 2*n-1;	// 包含n个叶子结点的哈夫曼树中共有2n-1个结点。

	(*HT) = (HuffmanTree)malloc(m*sizeof(HTNode));
	for(i=0;i<m;i++)	// 初始化
	{
		(*HT)[i].parent = (*HT)[i].lch = (*HT)[i].rch = -1;	// 下标由0开始
	}

	for(i=0;i<n;i++)	//	输入权重
	{
		scanf("%d", &( (*HT)[i].weight ));
	}

	// 建立哈夫曼树
	for(i=n;i<m;i++)
	{
		int s1 = 0;
		int s2 = 0;
		Select((*HT),i,&s1,&s2);
		(*HT)[s1].parent = (*HT)[s2].parent = i;
		(*HT)[i].weight = (*HT)[s1].weight + (*HT)[s2].weight;

		(*HT)[i].lch = s1;
		(*HT)[i].rch = s2;
	}

	return 1;
}

void CreateHuffmanCode(HuffmanTree HT,HuffmanCode* HC , int n)
{
	char* cd = (char*)malloc(sizeof(char)*n);	//	临时编码存储数组
	int i = 0;	//	循环计数遍历	

	(*HC) = (HuffmanCode)malloc(sizeof(char*)*n);

	cd[n-1] = '\0';

	for(i=0;i<n;++i)
	{
		int start = n-1;
		int c = i;
		int f = HT[i].parent;
		while(f != -1)
		{
			--start;
			if(HT[f].lch == c)
				cd[start] = '0';
			else
				cd[start] = '1';
			c = f;
			f = HT[f].parent;
		}
		(*HC)[i] = (char*)malloc(sizeof(char)*(n-start));
		//printf("%s\n",&(cd[start]));
		strcpy((*HC)[i],&(cd[start]));
	}

	free(cd);

}