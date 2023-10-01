#ifndef __SQSTRING_H__
#define __SQSTRING_H__

/*	由于c语言自带诸多字符串函数，本结构并未写完，因为目前没必要	*/
#include <stdlib.h>
//#include <assert.h>

typedef struct SqString{
	char* ch;		// 存放字符的数组
	int length;		// 字符串当前长度
	int strSize;	// 字符串字符上限('\0'不算在内)
}SqString;

// BF算法求字串位置
// S为主串 T为模式(字串) pos为开始查找的位置，返回值为子串第一个元素在主串的下标
int index_BF(SqString* S,SqString* T,int pos);
// KMP算法求字串位置
// S为主串 T为模式(字串) pos为开始查找的位置，返回值为子串第一个元素在主串的下标
int index_KMP(SqString* S,SqString* T,int pos);

#endif