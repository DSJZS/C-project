#define _CRT_SECURE_NO_WARNINGS 1

#include "EightQueens.h"

int total = 0;

void ShowQueens(SqStack* Q)
{
	int arr[N][N] = {0};
	int row = 0;
	int i=0;
	while(row< N)
	{
		arr[row][Q->base[row]] = 1;
		++row;
	}
	for(i=0;i<N;++i)
	{
		int j = 0;
		printf("|");
		for(j=0;j<N;++j)
		{
			if(arr[i][j])
				printf(" * |");
			else
				printf("   |");
		}
		printf("\n");
	}
}

int IsOK(SqStack* Q, int row, int col)
{
	int r=0,l=0;
	while(r < (Q->top - Q->base))
	{
		l = Q->base[r];
		if( (l == col) || (r == row) || ( (col-l)==(row-r) ) || ( (l-col)==(row-r) ))
			return 0;
		++r;
	}
	return 1;
}

void Queens(SqStack* Q, int row)
{
	int col = 0;

	for(col=0; col<N ; ++col)
	{
		if(IsOK(Q,row,col))
		{
			Push_SqS(Q,col);
			++row;
		}
		else
		{
			continue;
		}
		if(row == N)
		{
			++total;
			printf("µÚ %d ¸ö½â\n", total);
			ShowQueens(Q);
			Pop_SqS(Q,NULL);
			--row;
		}
		else
		{
			Queens(Q,row);
			Pop_SqS(Q,NULL);
			--row;
		}
	}
}

