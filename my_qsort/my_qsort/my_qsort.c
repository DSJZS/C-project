#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

// elem-数组元素指针 width-数组元素大小
// 作用：将一个数组的某一个元素与下一个元素进行互换
void swap(void* elem, size_t width)
{
	int i = 0;
	for(i=0;i<width;i++)
	{
		char ret = 0;
		ret = *((char*)elem+i);
		*((char*)elem+i) = *((char*)elem+i+width);
		*((char*)elem+i+width) = ret;
	}
}

//base-数组首元素地址  num-数组元素个数 width-数组元素大小 compare-比较函数指针
//作用：对一个元素类型任意的数组进行排序
void my_qsort(void *base, size_t num, size_t width, int (*compare)(const void *, const void*))
{
	int i = 0;
	
	for( i=0 ; i< num-1 ; i++ )
	{
		int j = 0;
		for(j=0;j< num-1-i;j++)
		{
			if(  (compare((char*)base+width*j,(char*)base+width*(j+1))) > 0 )
			{
				swap((char*)base+width*j,width);
			}
		}
	}
}

// p1、p2-数组元素指针
// 作用：比较整形大小, elem1指向的元素大于elem2指向的元素就返回>0的数字，相反则返回<0的数组，相同就返回0
int cmp_int(const void * elem1, const void* elem2)
{
	return *(int*)elem1 - *(int*)elem2;
}

int main()
{
	int arr[10] = {9,7,8,3,4,6,5,1,2};
	int  num = sizeof(arr)/sizeof(arr[0]);
	int width = sizeof(arr[0]);
	int i = 0;

	my_qsort(arr, num,width,cmp_int);

	for(i=0;i< num;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");

	return 0;
}
