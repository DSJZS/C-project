#ifndef __NUMSYSCON_H__
#define __NUMSYSCON_H__

#include "SqStack.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

#define CAPACITY 100

enum NumSystem{
	BIN = 2,	// 二进制
	OCT = 8,	// 八进制
	DEC = 10,	// 十进制
	HEX = 16	// 十六进制
};

// 将输入的数字字符倒置存入栈
int scanNum(SqStack* SNum);
// 将倒置存入栈的数字字符按正常顺序打印在屏幕上
void printNum(SqStack* SNum);
// 进制转换
int NumSysToNumSys(SqStack* SNum,int srcNumSys ,int destNumSys);


#endif