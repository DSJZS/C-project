#define _CRT_SECURE_NO_WARNINGS 1

#include "NumSysCon.h"

void menu()
{
	printf("# 100字节数制转换器 #\n");
	printf("# 仅支持100个数字输入输出，小数点会占用一个数字的位置 #\n");
	printf("# 超过上限或者输入标点符号等字符会得出错误答案或者报错 #\n");
	printf("# 小数位最多十位 #\n");
	printf("请按需求输入以下数字选项\n");
	printf("0.\t关闭数制转换器\n");
	printf("1.\t二转八\n");
	printf("2.\t二转十\n");
	printf("3.\t二转十六\n");
	printf("4.\t八转二\n");
	printf("5.\t八转十\n");
	printf("6.\t八转十六\n");
	printf("7.\t十转二\n");
	printf("8.\t十转八\n");
	printf("9.\t十转十六\n");
	printf("10.\t十六转二\n");
	printf("11.\t十六转八\n");
	printf("12.\t十六转十\n");
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
			printf("关闭成功\n");
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
			printf("输入错误，请重新输入\n");
			break;
		}
		system("pause");
		system("cls");
	} while (input);
	DestroyStack_SqS(&SNum);
	return 0;
}