#define _CRT_SECURE_NO_WARNINGS 1

#include "SequenceList.h"

// 交换同类型数据函数 elem1和elem2为需要交换数据的指针, elemSize为它们的大小
static Status swap(void* elem1, void* elem2, int elemSize)
{
	void* tmp = (void*)malloc(elemSize);
	if(tmp == NULL)
		return OVERFLOW;
	memcpy(tmp,elem1,elemSize);
	memcpy(elem1,elem2,elemSize);
	memcpy(elem2,tmp,elemSize);
	free(tmp);
	tmp = NULL;
	return OK;
}

static void* find_pointer_by_index(SqList* L ,int index)
{
	return (void*)((char*)(L->data) + index * (L->elemSize));
}

// 判断是否需要扩容，如果需要则扩容
static Status Capacity(SqList* L)
{
	if(L->current < L->capacity)
		return OK;
	else
	{
		void* tmp = (void*)realloc(L->data, (L->capacity + CAPACITY)*L->elemSize);
		if(NULL==tmp)
			return OVERFLOW;
		L->data = tmp;
		L->capacity += CAPACITY;
		return OK;
	}
	return ERROR;
}

// L 为需要销毁的顺序表的指针
void Destory_SqList(SqList* L)
{
	L->capacity = 0;
	L->current = 0;
	L->elemSize = 0;
	free(L->data);
	L->data = NULL;
}

// L 为需要清空的顺序表的指针
void Clear_SqList(SqList* L)
{
	L->current = 0;
}

// L 为需要返回当前元素个数的顺序表的指针
int GetSize_SqList(SqList* L)
{
	return L->current;
}

// L 为需要返回当前最大元素个数的顺序表的指针
int GetCapacity_SqList(SqList* L)
{
	return L->capacity;
}

// L 为需要判断是否为空的顺序表的指针
int IsEmpty_SqList(SqList* L)
{
	if(L->current)
		return FALSE;
	else
		return TRUE;
}

// L 为需要排序的顺序表的指针， cmpFun是排序函数
void Sort_SqList(SqList* L, int(*cmpFun)(const void*, const void*))
{
	qsort(L->data,L->current,L->elemSize,cmpFun);
}

// L1和L2 为需要相互交换的顺序表的指针
void Swap_SqList(SqList* L1,SqList* L2)
{
	swap(L1,L2,sizeof(SqList));
}

// L 为需要获取元素的顺序表的指针， i 为改元素下标
void* Get_Elem_SqList(SqList* L,int index)
{
	if(index<0)
		return NULL;
	return (void*)( (char*)(L->data) + index * (L->elemSize) );
}

// L 为需要获取元素的顺序表的指针
void* Get_Front_Elem_SqList(SqList* L)
{
	if(L->current)
		return L->data;
	return NULL;
}

// L 为需要获取元素的顺序表的指针
void* Get_Back_Elem_SqList(SqList* L)
{
	if(L->current)
		return Get_Elem_SqList(L,L->current-1);
	return NULL;
}

// L 为需要寻找元素的顺序表的指针,val为需要寻找的元素
void* Find_Elem_SqList(SqList* L, const void* val)
{
	if(L->current)
	{
		int i = 0;
		for(i=0;i<L->current;i++)
		{
			if( !(memcmp( Get_Elem_SqList(L,i) , val, L->elemSize)) )
				return Get_Elem_SqList(L,i);
		}
	}
	return NULL;
}

// L 为需要删除最后一个元素的顺序表的指针
Status Pop_Back_SqList(SqList* L)
{
	if(L->current)
	{
		--(L->current);
		return OK;
	}
	else
		return ERROR;
}

// L 为需要删除元素的顺序表的指针
Status Erase_Elem_SqList(SqList* L, int index)
{
	int i = 0;
	for(i=index;i<L->current-1;i++)
	{
		if( OVERFLOW == swap(Get_Elem_SqList(L,i),Get_Elem_SqList(L,i+1),L->elemSize))
			return ERROR;
	}
	return OK;
}

// L 为需要删除元素的顺序表的指针
Status Erase_Mul_Elem_SqList(SqList* L, int left, int right)
{
	if(right >= L->current)
	{
		L->current = left;
		return OK;
	}
	else if(left > L->current-1)
	{
		return ERROR;
	}
	else
	{
		int i = 0;
		for(i=right+1;i<L->current;i++)
		{
			swap(Get_Elem_SqList(L,left),Get_Elem_SqList(L,i),L->elemSize);
			left++;
		}
		L->current -= (right-left+1);
		return OK;
	}
	return ERROR;
}

// L 为需要尾部插入元素的顺序表的指针
Status Push_Back_SqList(SqList* L, void* val)
{
	void* p = NULL;
	Capacity(L);
	
	p=Get_Elem_SqList(L,L->current);
	memcpy(p,val,L->elemSize);
	++(L->current);

	return OK;
}

// L 为需要插入元素的顺序表的指针 
Status Front_Inset_SqList(SqList* L, void* val, int index)
{
	if(index >= L->current)
		return ERROR;
	else
	{
		int i = 0;
		Capacity(L);
		for(i=L->current;i>index;i--)
		{
			swap(Get_Elem_SqList(L,i),Get_Elem_SqList(L,i-1),L->elemSize);
		}
		memcpy(Get_Elem_SqList(L,index), val, L->elemSize);
		++(L->current);
		return OK;
	}
	return ERROR;
}

// L 为需要改变容量的顺序表的指针 
Status Cal_Capacity(SqList* L)
{
	if(L->capacity == L->current)
		return OK;
	else
	{
		void* tmp = (void*)realloc(L->data,L->current * L->elemSize);
		if(tmp == NULL)
			return OVERFLOW;
		L->data = tmp;
		return OK;
	}
	return ERROR;
}

// 通过判断函数查找顺序表中的一个元素，如果有则返回该元素的指针，如果没有则返回NULL
void* Locate_Elem_SqList(SqList* L, int (*cmp)(void* val))
{
	int i = 0;
	for(i=0;i<L->current;i++)
	{
		if(cmp(Get_Elem_SqList(L,i)))
			return Get_Elem_SqList(L,i);
	}
	return NULL;
}

// L 为需要初始化的顺序表的指针，n为元素大小
Status InitList_SqList(SqList* L, int elemSize)
{
	L->current = 0;
	L->capacity = SqListNUM;
	L->elemSize = elemSize;
	L->data = (void*)malloc(elemSize * SqListNUM);
	if(L->data == NULL)	// malloc开辟空间失败
	{
		perror("InitList_Sq malloc:");
		return OVERFLOW;	
	}

	//L->init = InitList_SqList;
	L->destory = Destory_SqList;
	L->clear = Clear_SqList;
	L->push_back = Push_Back_SqList;
	L->get = Get_Elem_SqList;
	L->get_size = GetSize_SqList;
	L->get_capacity = GetCapacity_SqList;
	L->empty = IsEmpty_SqList;
	L->sort = Sort_SqList;
	L->swap = Swap_SqList;
	L->front = Get_Front_Elem_SqList;
	L->back = Get_Back_Elem_SqList;
	L->find = Find_Elem_SqList;
	L->pop_back = Pop_Back_SqList;
	L->erase = Erase_Elem_SqList;
	L->erase_mul = Erase_Mul_Elem_SqList;
	L->push_back = Push_Back_SqList;
	L->front_inset = Front_Inset_SqList;
	L->cal_capacity = Cal_Capacity;
	L->locate = Locate_Elem_SqList;

	return OK;	//	初始化成功
}