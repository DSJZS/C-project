#define _CRT_SECURE_NO_WARNINGS 1

#include "NumSysCon.h"

void menu()
{
	printf("# 100�ֽ�����ת���� #\n");
	printf("# ��֧��100���������������С�����ռ��һ�����ֵ�λ�� #\n");
	printf("# �������޻�����������ŵ��ַ���ó�����𰸻��߱��� #\n");
	printf("# С��λ���ʮλ #\n");
	printf("�밴����������������ѡ��\n");
	printf("0.\t�ر�����ת����\n");
	printf("1.\t��ת��\n");
	printf("2.\t��תʮ\n");
	printf("3.\t��תʮ��\n");
	printf("4.\t��ת��\n");
	printf("5.\t��תʮ\n");
	printf("6.\t��תʮ��\n");
	printf("7.\tʮת��\n");
	printf("8.\tʮת��\n");
	printf("9.\tʮתʮ��\n");
	printf("10.\tʮ��ת��\n");
	printf("11.\tʮ��ת��\n");
	printf("12.\tʮ��תʮ\n");
	printf(":>");
};

int main()
{
	SqStack SNum;
	int input = 0;
	InitStack_SqS(&SNum,CAPACITY);
	do 
	{
		menu();
		scanf("%d",&input);
		switch(input)
		{
		case 0:
			printf("�رճɹ�\n");
			break;
		case 1:
			scanNum(&SNum);
			NumSysToNumSys(&SNum,BIN,OCT);
			printNum(&SNum);
			break;
		case 2:
			scanNum(&SNum);
			NumSysToNumSys(&SNum,BIN,DEC);
			printNum(&SNum);
			break;
		case 3:
			scanNum(&SNum);
			NumSysToNumSys(&SNum,BIN,HEX);
			printNum(&SNum);
			break;
		case 4:
			scanNum(&SNum);
			NumSysToNumSys(&SNum,OCT,BIN);
			printNum(&SNum);
			break;
		case 5:
			scanNum(&SNum);
			NumSysToNumSys(&SNum,OCT,DEC);
			printNum(&SNum);
			break;
		case 6:
			scanNum(&SNum);
			NumSysToNumSys(&SNum,OCT,HEX);
			printNum(&SNum);
			break;
		case 7:
			scanNum(&SNum);
			NumSysToNumSys(&SNum,DEC,BIN);
			printNum(&SNum);
			break;
		case 8:
			scanNum(&SNum);
			NumSysToNumSys(&SNum,DEC,OCT);
			printNum(&SNum);
			break;
		case 9:
			scanNum(&SNum);
			NumSysToNumSys(&SNum,DEC,HEX);
			printNum(&SNum);
			break;
		case 10:
			scanNum(&SNum);
			NumSysToNumSys(&SNum,HEX,BIN);
			printNum(&SNum);
			break;
		case 11:
			scanNum(&SNum);
			NumSysToNumSys(&SNum,HEX,OCT);
			printNum(&SNum);
			break;
		case 12:
			scanNum(&SNum);
			NumSysToNumSys(&SNum,HEX,DEC);
			printNum(&SNum);
			break;
		default:
			printf("�����������������\n");
			break;
		}
		system("pause");
		system("cls");
	} while (input);
	DestroyStack_SqS(&SNum);
	return 0;
}