#define _CRT_SECURE_NO_WARNINGS 1

#include "SequenceList.h"

// ����ͬ�������ݺ��� elem1��elem2Ϊ��Ҫ�������ݵ�ָ��, elemSizeΪ���ǵĴ�С
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

// �ж��Ƿ���Ҫ���ݣ������Ҫ������
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

// L Ϊ��Ҫ���ٵ�˳����ָ��
void Destory_SqList(SqList* L)
{
	L->capacity = 0;
	L->current = 0;
	L->elemSize = 0;
	free(L->data);
	L->data = NULL;
}

// L Ϊ��Ҫ��յ�˳����ָ��
void Clear_SqList(SqList* L)
{
	L->current = 0;
}

// L Ϊ��Ҫ���ص�ǰԪ�ظ�����˳����ָ��
int GetSize_SqList(SqList* L)
{
	return L->current;
}

// L Ϊ��Ҫ���ص�ǰ���Ԫ�ظ�����˳����ָ��
int GetCapacity_SqList(SqList* L)
{
	return L->capacity;
}

// L Ϊ��Ҫ�ж��Ƿ�Ϊ�յ�˳����ָ��
int IsEmpty_SqList(SqList* L)
{
	if(L->current)
		return FALSE;
	else
		return TRUE;
}

// L Ϊ��Ҫ�����˳����ָ�룬 cmpFun��������
void Sort_SqList(SqList* L, int(*cmpFun)(const void*, const void*))
{
	qsort(L->data,L->current,L->elemSize,cmpFun);
}

// L1��L2 Ϊ��Ҫ�໥������˳����ָ��
void Swap_SqList(SqList* L1,SqList* L2)
{
	swap(L1,L2,sizeof(SqList));
}

// L Ϊ��Ҫ��ȡԪ�ص�˳����ָ�룬 i Ϊ��Ԫ���±�
void* Get_Elem_SqList(SqList* L,int index)
{
	if(index<0)
		return NULL;
	return (void*)( (char*)(L->data) + index * (L->elemSize) );
}

// L Ϊ��Ҫ��ȡԪ�ص�˳����ָ��
void* Get_Front_Elem_SqList(SqList* L)
{
	if(L->current)
		return L->data;
	return NULL;
}

// L Ϊ��Ҫ��ȡԪ�ص�˳����ָ��
void* Get_Back_Elem_SqList(SqList* L)
{
	if(L->current)
		return Get_Elem_SqList(L,L->current-1);
	return NULL;
}

// L Ϊ��ҪѰ��Ԫ�ص�˳����ָ��,valΪ��ҪѰ�ҵ�Ԫ��
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

// L Ϊ��Ҫɾ�����һ��Ԫ�ص�˳����ָ��
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

// L Ϊ��Ҫɾ��Ԫ�ص�˳����ָ��
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

// L Ϊ��Ҫɾ��Ԫ�ص�˳����ָ��
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

// L Ϊ��Ҫβ������Ԫ�ص�˳����ָ��
Status Push_Back_SqList(SqList* L, void* val)
{
	void* p = NULL;
	Capacity(L);
	
	p=Get_Elem_SqList(L,L->current);
	memcpy(p,val,L->elemSize);
	++(L->current);

	return OK;
}

// L Ϊ��Ҫ����Ԫ�ص�˳����ָ�� 
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

// L Ϊ��Ҫ�ı�������˳����ָ�� 
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

// ͨ���жϺ�������˳����е�һ��Ԫ�أ�������򷵻ظ�Ԫ�ص�ָ�룬���û���򷵻�NULL
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

// L Ϊ��Ҫ��ʼ����˳����ָ�룬nΪԪ�ش�С
Status InitList_SqList(SqList* L, int elemSize)
{
	L->current = 0;
	L->capacity = SqListNUM;
	L->elemSize = elemSize;
	L->data = (void*)malloc(elemSize * SqListNUM);
	if(L->data == NULL)	// malloc���ٿռ�ʧ��
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

	return OK;	//	��ʼ���ɹ�
}