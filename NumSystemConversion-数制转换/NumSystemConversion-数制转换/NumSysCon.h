#ifndef __NUMSYSCON_H__
#define __NUMSYSCON_H__

#include "SqStack.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

#define CAPACITY 100

enum NumSystem{
	BIN = 2,	// ������
	OCT = 8,	// �˽���
	DEC = 10,	// ʮ����
	HEX = 16	// ʮ������
};

// ������������ַ����ô���ջ
int scanNum(SqStack* SNum);
// �����ô���ջ�������ַ�������˳���ӡ����Ļ��
void printNum(SqStack* SNum);
// ����ת��
int NumSysToNumSys(SqStack* SNum,int srcNumSys ,int destNumSys);


#endif