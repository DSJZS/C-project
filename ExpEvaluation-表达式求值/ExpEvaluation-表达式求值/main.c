#define _CRT_SECURE_NO_WARNINGS 1

#include "ExpEvaluation.h"


void menu()
{
	printf("# 四则运算表达式求值 #\n");
	printf("# 字符个数上限为 %d  (空格不参加字符个数的计算) #\n",EXPMSIZE);
	printf("# 除了0-9以外，只能出现如下字符 #\n");
	printf("字符	含义\n");
	printf(" +		加法\n");
	printf(" -		减法\n");
	printf(" *		乘法\n");
	printf(" /		除法\n");
	printf("()		括号\n");
	printf("		空格\n");

	printf("输入你需要求值的表达式>:\n");
}

int main()
{
	SqStack Exp;	// 表达式变量
	int input;
	int result = 0;

	InitStack_SqS(&Exp,EXPMSIZE+1);	// 界限符号用#代替，因此+1字符

	do{
		menu();

		ScanExp(&Exp);
		result = CalExp(&Exp);
		printf("结果为：%d\n", result);

		system("pause");
		system("cls");
		printf("是否需要再次计算？不需要的话输入0，否则输入非0字符\n:>");
		scanf("%d",&input);
		system("cls");
		while('\n'!=getchar());
	}while(input);
	DestroyStack_SqS(&Exp);
	return 0;
}