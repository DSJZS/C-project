#ifndef __LINKSTRING_H__
#define __LINKSTRING_H__

/*	本链串为单链串	*/
/*	由于c语言自带诸多字符串函数，本结构并未写完，因为目前没必要	*/

typedef struct Chunk{
	char* ch;	// 数据域
	struct Chunk* next;	// 指针域
}Chunk;	// 字符块结点

typedef struct LinkString{
	Chunk *head,*tail;	// 头指针，尾指针
	int strlen;	// 串的长度
	int chunkSize;	// 每个块的大小
}LinkString;

#endif