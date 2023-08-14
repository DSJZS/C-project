#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

// elem-����Ԫ��ָ�� width-����Ԫ�ش�С
// ���ã���һ�������ĳһ��Ԫ������һ��Ԫ�ؽ��л���
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

//base-������Ԫ�ص�ַ  num-����Ԫ�ظ��� width-����Ԫ�ش�С compare-�ȽϺ���ָ��
//���ã���һ��Ԫ����������������������
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

// p1��p2-����Ԫ��ָ��
// ���ã��Ƚ����δ�С, elem1ָ���Ԫ�ش���elem2ָ���Ԫ�ؾͷ���>0�����֣��෴�򷵻�<0�����飬��ͬ�ͷ���0
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
