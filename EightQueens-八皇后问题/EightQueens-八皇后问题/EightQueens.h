#ifndef __EIGHTQUEENS_H__
#define __EIGHTQUEENS_H__

#include "SqStack.h"
#include <stdio.h>
#include <stdlib.h>

#define N 8	// 几行几列，几个皇后

// 查找合适的棋盘摆放
void Queens(SqStack* Q, int row);
// 在屏幕上显示棋盘信息
void ShowQueens(SqStack* Q);
#endif