#ifndef __EXPEVALUATION_H__
#define __EXPEVALUATION_H__

#include "SqStack.h"
#include <stdio.h>
#include <math.h>

#define EXPMSIZE 100

// ������ʽ
void ScanExp(SqStack* Exp);
// ������ʽ
int CalExp(SqStack* Exp);

#endif