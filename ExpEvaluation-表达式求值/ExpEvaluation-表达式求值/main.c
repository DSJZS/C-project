#define _CRT_SECURE_NO_WARNINGS 1

#include "ExpEvaluation.h"


void menu()
{
	printf("# ����������ʽ��ֵ #\n");
	printf("# �ַ���������Ϊ %d  (�ո񲻲μ��ַ������ļ���) #\n",EXPMSIZE);
	printf("# ����0-9���⣬ֻ�ܳ��������ַ� #\n");
	printf("�ַ�	����\n");
	printf(" +		�ӷ�\n");
	printf(" -		����\n");
	printf(" *		�˷�\n");
	printf(" /		����\n");
	printf("()		����\n");
	printf("		�ո�\n");

	printf("��������Ҫ��ֵ�ı��ʽ>:\n");
}

int main()
{
	SqStack Exp;	// ���ʽ����
	int input;
	int result = 0;

	InitStack_SqS(&Exp,EXPMSIZE+1);	// ���޷�����#���棬���+1�ַ�

	do{
		menu();

		ScanExp(&Exp);
		result = CalExp(&Exp);
		printf("���Ϊ��%d\n", result);

		system("pause");
		system("cls");
		printf("�Ƿ���Ҫ�ٴμ��㣿����Ҫ�Ļ�����0�����������0�ַ�\n:>");
		scanf("%d",&input);
		system("cls");
		while('\n'!=getchar());
	}while(input);
	DestroyStack_SqS(&Exp);
	return 0;
}