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

#define SqListNUM 1 // 顺序表初始大小
#define CAPACITY 1	// 顺序表默认扩容时扩容的容量大小

typedef int Status;

typedef struct SqList
{
	// 初始化
	Status (*init)( struct SqList*,int);
	// 销毁
	void (*destory)( struct SqList*);
	// 清空
	void (*clear)( struct SqList*);
	// 通过下标获取某一个元素
	void* (*get)(  struct SqList*, int);
	// 通过值顺序表中的一个元素，如果有则返回该元素的指针，如果没有则返回NULL
	void* (*find)(  struct SqList*, const void*);
	// 通过判断函数查找顺序表中的一个元素，如果有则返回该元素的指针，如果没有则返回NULL
	void* (*locate)(  struct SqList*, int (*)(void* val));
	// 返回指向第一个元素的指针
	void* (*front)( struct SqList*);
	// 返回指向最后一个元素的指针
	void* (*back)( struct SqList*);
	// 删除顺序表最后一个元素
	Status (*pop_back)( struct SqList*);
	// 通过下标删除顺序表的某一个元素
	Status (*erase)( struct SqList*, int);
	// 通过下标删除顺序表的某一个区间内元素
	Status (*erase_mul)( struct SqList*, int, int);
	// 将一个元素插入到顺序表尾部
	Status (*push_back)( struct SqList*, void*);
	// 在下标指向的元素之前插入一个元素
	Status (*front_inset)( struct SqList*, void*, int);
	// 获取元素个数
	int (*get_size)( struct SqList*);
	// 获取当前最大元素个数
	int (*get_capacity)( struct SqList*);
	// 判断顺序表是否为空
	int (*empty)( struct SqList*);
	// 检查最多元素个数是否与当前元素个数一致，如果不一致，使它们相等
	Status (*cal_capacity)( struct SqList*);
	// 排序顺序表
	void (*sort)( struct SqList*, int(*)(const void*, const void*));
	// 交换两个顺序表数据
	void (*swap)( struct SqList*, struct SqList*);


	void* data;		// 存放数组首元素地址
	int current;	// 记录当前元素个数
	int capacity;	// 记录最多元素个数
	int elemSize;	// 记录元素的大小
}SqList;



// 初始化操作，建立一个空的顺序表
Status InitList_SqList(SqList* L, int n);
// 销毁已有的顺序表
void Destory_SqList(SqList* L);
// 清空已有的顺序表
void Clear_SqList(SqList* L);
// 获得顺序表当前元素个数
int GetSize_SqList(SqList* L);
// 获得顺序表当前最大元素个数
int GetCapacity_SqList(SqList* L);
// 判断顺序表是否为空
int IsEmpty_SqList(SqList* L);
// 排序顺序表
void Sort_SqList(SqList* L, int(*cmpFun)(const void*, const void*));
// 交换存放同类型元素的顺序表的数据
void Swap_SqList(SqList* L1,SqList* L2);
// 以下标的形式寻找顺序表中的相应元素，并返回其指针
void* Get_Elem_SqList(SqList* L,int index);
// 返回指向第一个元素的指针
void* Get_Front_Elem_SqList(SqList* L);
// 返回指向最后一个元素的指针
void* Get_Back_Elem_SqList(SqList* L);
// 通过值查找顺序表中的一个元素，如果有则返回该元素的指针，如果没有则返回NULL
void* Find_Elem_SqList(SqList* L, const void* val);
// 通过判断函数查找顺序表中的一个元素，如果有则返回该元素的指针，如果没有则返回NULL
void* Locate_Elem_SqList(SqList* L, int (*cmp)(void* val));
// 删除顺序表最后一个元素
Status Pop_Back_SqList(SqList* L);
// 通过下标删除顺序表的某一个元素
Status Erase_Elem_SqList(SqList* L, int index);
// 通过下标删除顺序表的某一个区间内元素
Status Erase_Mul_Elem_SqList(SqList* L, int left, int right);
// 将一个元素插入到顺序表尾部
Status Push_Back_SqList(SqList* L, void* val);
// 在下标指向的元素之前插入一个元素
Status Front_Inset_SqList(SqList* L, void* val, int index);
// 检查最多元素个数是否与当前元素个数一致，如果不一致，使它们相等
Status Cal_Capacity(SqList* L);



#endif