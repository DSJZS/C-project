#ifndef __EXPEVALUATION_H__
#define __EXPEVALUATION_H__

#include "SqStack.h"
#include <stdio.h>
#include <math.h>

#define EXPMSIZE 100

// 输入表达式
void ScanExp(SqStack* Exp);
// 计算表达式
int CalExp(SqStack* Exp);

#endif