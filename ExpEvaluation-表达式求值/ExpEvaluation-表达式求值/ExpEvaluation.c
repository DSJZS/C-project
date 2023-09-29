#define _CRT_SECURE_NO_WARNINGS 1

#include "ExpEvaluation.h"

static int cal(int x,int y,char opertor)
{
	switch(opertor)
	{
	case '+':
		return (x+y);
	case '-':
		return (x-y);
	case '*':
		return (x*y);
	case '/':
		return (x/y);
	default:
		return 0;
	}
}

void ScanExp(SqStack* Exp)
{
	char exp[EXPMSIZE+1] = "";
	int i = 0;
	fgets(exp,EXPMSIZE+1,stdin);
	Push_SqS(Exp,(int)('#'));
	while(  (exp[i] != '\n')  &&  (exp[i] != '\0')  )
	{
		if(exp[i] != ' ')
			Push_SqS(Exp,(int)(exp[i]));
		++i;
	}

}

int CalExp(SqStack* Exp)
{
	int result = 0;
	SqStack exp_operand;	//	²Ù×÷Êı
	SqStack exp_operator;	//	ÔËËã·û

	int tmp = 0;
	int flag = 0;
	int num = 0;

	InitStack_SqS(&exp_operand,EXPMSIZE);
	InitStack_SqS(&exp_operator,EXPMSIZE);

	while(!IsEmpty_SqS(Exp))
	{
		Pop_SqS(Exp,&tmp);

		if( ((int)tmp >= (int)('0')) && ((int)tmp <= (int)('9')) )
		{
			num += (int)pow(10,flag)*((int)tmp-48);
			++flag;
		}
		else if( ((int)tmp == (int)('+')) || ((int)tmp == (int)('-')))
		{
			int opertor = 0;
			int num1,num2;

			if(flag)
			{
				flag = 0;
				Push_SqS(&exp_operand,num);
				num = 0;
			}

			GetTop_SqS(&exp_operator,&opertor);
			while( (opertor == '*') || (opertor == '/') )
			{
				Pop_SqS(&exp_operand,&num1);
				Pop_SqS(&exp_operand,&num2);
				Pop_SqS(&exp_operator,&opertor);
				Push_SqS(&exp_operand,cal(num1,num2,opertor));
				if(!GetTop_SqS(&exp_operator,&opertor))
					break;
			}

			Push_SqS(&exp_operator,(int)tmp);

		}
		else if (((int)tmp == (int)('*')) || ((int)tmp == (int)('/')))
		{
			Push_SqS(&exp_operator,(int)tmp);

			if(flag)
			{
				flag = 0;
				Push_SqS(&exp_operand,num);
				num = 0;
			}
		}
		else if( ((int)tmp == (int)(')')))
		{
			Push_SqS(&exp_operator,(int)tmp);

			if(flag)
			{
				flag = 0;
				Push_SqS(&exp_operand,num);
				num = 0;
			}
		}
		else if( ( (int)tmp == (int)('(') ) || ( (int)tmp == (int)('#') ) )
		{
			int opertor = 0;
			int num1,num2;

			if(flag)
			{
				flag = 0;
				Push_SqS(&exp_operand,num);
				num = 0;
			}
			GetTop_SqS(&exp_operator,&opertor);
			while(opertor != ')')
			{
				if(IsEmpty_SqS(&exp_operator))
					break;
				Pop_SqS(&exp_operand,&num1);
				Pop_SqS(&exp_operand,&num2);
				Pop_SqS(&exp_operator,&opertor);
				Push_SqS(&exp_operand,cal(num1,num2,opertor));
				GetTop_SqS(&exp_operator,&opertor);
			}
			if(opertor == ')')
				Pop_SqS(&exp_operator,NULL);
		}
		else
		{
			printf("´íÎó×Ö·û\n");
			return result;
		}
	}
	Pop_SqS(&exp_operand,&result);

	DestroyStack_SqS(&exp_operand);
	DestroyStack_SqS(&exp_operator);

	return result;
}