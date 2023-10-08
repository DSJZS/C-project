#define _CRT_SECURE_NO_WARNINGS 1

#include "HuffmanTree.h"

int main()
{
	HuffmanTree HT;
	HuffmanCode HC;
	int n = 7;
	int i = 0;
	CreateHuffmanTree(&HT,n);
	CreateHuffmanCode(HT,&HC,n);
	for(i=0;i<n;i++)
	{
		printf("%s\n", HC[i] );
	}
	return 0;
}