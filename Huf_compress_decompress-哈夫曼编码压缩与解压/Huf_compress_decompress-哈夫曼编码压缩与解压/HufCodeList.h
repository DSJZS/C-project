#ifndef __HUFCODELIST_H__
#define __HUFCODELIST_H__

/*	字符哈夫曼码列表	*/

#include "FreqList.h"	/*	struct *FreqList - Freq	*/
#include "error.h"	/*	enum Status			func ConfirmError*/
#include <stdlib.h>	/*	func malloc - calloc - free	*/
#include <string.h> /*	func strcpy	*/

typedef struct HufCode{
	unsigned char c;	// 字符
	char* hcode;	//	哈夫曼编码
}HufCode,*HufCodeList;

/*	创建哈夫曼编码表
形参：
FL - 存放各个字符频率的列表(哈夫曼树)
*HCL - 存放各个字符哈夫曼编码的数组 
count - 记录字符的种类个数
返回值：
OK - 表示正常
OVERFLOW - 表示动态内存空间开辟失败
*/
Status CreateHufCodeList(FreqList FL,HufCodeList* HCL,int count);

/*	销毁哈夫曼编码表
形参：
FL - 存放各个字符频率的列表(哈夫曼树)
count - 记录字符的种类个数
返回值：
无
*/
void DestroyHufCodeList(HufCodeList HCL,int count);

#endif