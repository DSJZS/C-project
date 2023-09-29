#define _CRT_SECURE_NO_WARNINGS 1

#include "NumSysCon.h"

static void my_reverse(char* str)
{
	int len  = strlen(str);
	int i = 0;
	char tmp = 0;
	for(i=0;i<len-i-1;++i)
	{
		tmp = str[i];
		str[i] = str[len-i-1];
		str[len-i-1] = tmp;
	}
}

int scanNum(SqStack* SNum)
{
	char strNum[CAPACITY+1] = "";
	int i = 0;

	while('\n' != getchar());

	printf("输入数字:>");
	if( !fgets(strNum,CAPACITY+1,stdin) )
		return 0;


	for(i=0;strNum[i] != '\0' && strNum[i] != '\n';++i)
		if( Push_SqS(SNum,strNum[i]) == 0)
			return 0;
	return 1;
}

void printNum(SqStack* SNum)
{
	char tmp = 0;
	while(!IsEmpty_SqS(SNum))
	{
		Pop_SqS(SNum,&tmp);
		printf("%c",tmp);
	}
	printf("\n");
}

int NumSysToNumSys(SqStack* SNum,int srcNumSys ,int destNumSys)
{
	int I = 0;	// 整数位
	int F = 0;	// 小数位
	int iCount = 0;	//	有多少整数位
	int fCount = 0;	//	有多少小数位
	

	char tmp = 0;
	char strNum[CAPACITY+1] = "";
	while(!IsEmpty_SqS(SNum))
	{
		Pop_SqS(SNum,&tmp);
		if(tmp == '.')
		{
			F = I;
			I = 0;
			fCount = iCount;
			iCount = 0;
			continue;
		}
		else if(iCount)
		{
			if( (tmp>='0') && (tmp <= '9') )
				I += (int)pow(srcNumSys,iCount) * (tmp-48);
			else
				I += (int)pow(srcNumSys,iCount) * (tmp-55);
		}
		else
		{
			if( (tmp>='0') && (tmp <= '9') )
				I += (tmp-48);
			else
				I += (tmp-55);
		}
		
		++iCount;
	}

	ClearStack_SqS(SNum);
	tmp = 0;
	if(fCount)
	{
		int i = 10;
		strNum[tmp] = '.';
		++tmp;
		
		do{
			
			if(( ((int)(F * destNumSys / pow(10,fCount)) % destNumSys) >= 0 ) && ( ((int)(F * destNumSys / pow(10,fCount)) % destNumSys) <= 9 ))
				strNum[tmp] = (char)(((int)(F * destNumSys / pow(10,fCount)) % destNumSys)+48);
			else 
				strNum[tmp] = (char)(((int)(F * destNumSys / pow(10,fCount)) % destNumSys)+55);
			F =  F * destNumSys % (int)pow(10,fCount);
			++tmp,--i;
		}while(F && i);
		my_reverse(strNum);
	}
	do 
	{
		if(( (I%destNumSys) >= 0 ) && ( (I%destNumSys) <= 9 ))
			strNum[tmp] = (char)(I%destNumSys+48);
		else 
			strNum[tmp] = (char)(I%destNumSys+55);
		++tmp;
	} while (I/=destNumSys);

	for(tmp=0;strNum[tmp] != '\0' && strNum[tmp] != '\n';++tmp)
	{
		if( Push_SqS(SNum,strNum[tmp]) == 0)
			return 0;
	}
	return 1;
}