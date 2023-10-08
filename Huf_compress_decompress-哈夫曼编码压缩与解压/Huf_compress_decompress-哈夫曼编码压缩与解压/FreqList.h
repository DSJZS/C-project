#ifndef __HUFNDOE_H__
#define __HUFNDOE_H__

/*	字符频率列表	*/


#include "error.h"	/*	enum Status			func ConfirmError*/
#include "memsize.h"	/*	func get_file_size	*/
#include <stdlib.h>	/*	func malloc - free	*/
#include <stdio.h> /*	func fopen - fclose - fgetc - feof - ferror	*/


//	存放字符的频率
typedef struct CharInfo{
	char c;		//	字符
	long long freq;	//	字符的频率
}CharInfo;

//	哈夫曼树
typedef struct Freq{
	CharInfo cInfo;	//	存放字符及其频率
	int parent,lch,rch;	//	双亲，左右孩子下标
}Freq,*FreqList;

/*	遍历目标文件，创建字符频率表
形参：
FL - 需要创建的字符频率的列表(哈夫曼树)
srcfile - 目标文件名字符串
*count - 记录字符个数
返回值：
OK - 表示正常
OVERFLOW - 表示动态内存空间开辟失败
NOFOUND - 表示目前文件未找到
UNKNOW - 表示未知错误
*/
Status CreateFreqList(FreqList* FL,char* srcfile, int* count);

/*	从压缩包中读取字符频率列表(哈夫曼树)
参数;
FL - 存入读取内容的字符频率的列表(哈夫曼树)
pfIn - 压缩包的文件指针
count - 记录字符个数
返回值：
OK - 表示正常
OVERFLOW - 表示动态内存空间开辟失败
UNKNOW - 表示未知错误
*/
Status ReadFreqList(FreqList* FL,FILE* pfIn, int count);

/*	销毁字符频率表	
形参：
FL - 需要销毁的字符频率的列表(哈夫曼树)
返回值：
无
*/
void DestroyFreqList(FreqList FL);



#endif