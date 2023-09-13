#ifndef __SEQUENCELIST_H__
#define __SEQUENCELIST_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

#define SqListNUM 1 // ˳����ʼ��С
#define CAPACITY 1	// ˳���Ĭ������ʱ���ݵ�������С

typedef int Status;

typedef struct SqList
{
	// ��ʼ��
	Status (*init)( struct SqList*,int);
	// ����
	void (*destory)( struct SqList*);
	// ���
	void (*clear)( struct SqList*);
	// ͨ���±��ȡĳһ��Ԫ��
	void* (*get)(  struct SqList*, int);
	// ͨ��ֵ˳����е�һ��Ԫ�أ�������򷵻ظ�Ԫ�ص�ָ�룬���û���򷵻�NULL
	void* (*find)(  struct SqList*, const void*);
	// ͨ���жϺ�������˳����е�һ��Ԫ�أ�������򷵻ظ�Ԫ�ص�ָ�룬���û���򷵻�NULL
	void* (*locate)(  struct SqList*, int (*)(void* val));
	// ����ָ���һ��Ԫ�ص�ָ��
	void* (*front)( struct SqList*);
	// ����ָ�����һ��Ԫ�ص�ָ��
	void* (*back)( struct SqList*);
	// ɾ��˳������һ��Ԫ��
	Status (*pop_back)( struct SqList*);
	// ͨ���±�ɾ��˳����ĳһ��Ԫ��
	Status (*erase)( struct SqList*, int);
	// ͨ���±�ɾ��˳����ĳһ��������Ԫ��
	Status (*erase_mul)( struct SqList*, int, int);
	// ��һ��Ԫ�ز��뵽˳���β��
	Status (*push_back)( struct SqList*, void*);
	// ���±�ָ���Ԫ��֮ǰ����һ��Ԫ��
	Status (*front_inset)( struct SqList*, void*, int);
	// ��ȡԪ�ظ���
	int (*get_size)( struct SqList*);
	// ��ȡ��ǰ���Ԫ�ظ���
	int (*get_capacity)( struct SqList*);
	// �ж�˳����Ƿ�Ϊ��
	int (*empty)( struct SqList*);
	// ������Ԫ�ظ����Ƿ��뵱ǰԪ�ظ���һ�£������һ�£�ʹ�������
	Status (*cal_capacity)( struct SqList*);
	// ����˳���
	void (*sort)( struct SqList*, int(*)(const void*, const void*));
	// ��������˳�������
	void (*swap)( struct SqList*, struct SqList*);


	void* data;		// ���������Ԫ�ص�ַ
	int current;	// ��¼��ǰԪ�ظ���
	int capacity;	// ��¼���Ԫ�ظ���
	int elemSize;	// ��¼Ԫ�صĴ�С
}SqList;



// ��ʼ������������һ���յ�˳���
Status InitList_SqList(SqList* L, int n);
// �������е�˳���
void Destory_SqList(SqList* L);
// ������е�˳���
void Clear_SqList(SqList* L);
// ���˳���ǰԪ�ظ���
int GetSize_SqList(SqList* L);
// ���˳���ǰ���Ԫ�ظ���
int GetCapacity_SqList(SqList* L);
// �ж�˳����Ƿ�Ϊ��
int IsEmpty_SqList(SqList* L);
// ����˳���
void Sort_SqList(SqList* L, int(*cmpFun)(const void*, const void*));
// �������ͬ����Ԫ�ص�˳��������
void Swap_SqList(SqList* L1,SqList* L2);
// ���±����ʽѰ��˳����е���ӦԪ�أ���������ָ��
void* Get_Elem_SqList(SqList* L,int index);
// ����ָ���һ��Ԫ�ص�ָ��
void* Get_Front_Elem_SqList(SqList* L);
// ����ָ�����һ��Ԫ�ص�ָ��
void* Get_Back_Elem_SqList(SqList* L);
// ͨ��ֵ����˳����е�һ��Ԫ�أ�������򷵻ظ�Ԫ�ص�ָ�룬���û���򷵻�NULL
void* Find_Elem_SqList(SqList* L, const void* val);
// ͨ���жϺ�������˳����е�һ��Ԫ�أ�������򷵻ظ�Ԫ�ص�ָ�룬���û���򷵻�NULL
void* Locate_Elem_SqList(SqList* L, int (*cmp)(void* val));
// ɾ��˳������һ��Ԫ��
Status Pop_Back_SqList(SqList* L);
// ͨ���±�ɾ��˳����ĳһ��Ԫ��
Status Erase_Elem_SqList(SqList* L, int index);
// ͨ���±�ɾ��˳����ĳһ��������Ԫ��
Status Erase_Mul_Elem_SqList(SqList* L, int left, int right);
// ��һ��Ԫ�ز��뵽˳���β��
Status Push_Back_SqList(SqList* L, void* val);
// ���±�ָ���Ԫ��֮ǰ����һ��Ԫ��
Status Front_Inset_SqList(SqList* L, void* val, int index);
// ������Ԫ�ظ����Ƿ��뵱ǰԪ�ظ���һ�£������һ�£�ʹ�������
Status Cal_Capacity(SqList* L);



#endif