#ifndef __EIGHTQUEENS_H__
#define __EIGHTQUEENS_H__

#include "SqStack.h"
#include <stdio.h>
#include <stdlib.h>

#define N 8	// ���м��У������ʺ�

// ���Һ��ʵ����̰ڷ�
void Queens(SqStack* Q, int row);
// ����Ļ����ʾ������Ϣ
void ShowQueens(SqStack* Q);
#endif