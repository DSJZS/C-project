#ifndef __SQSTRING_H__
#define __SQSTRING_H__

/*	����c�����Դ�����ַ������������ṹ��δд�꣬��ΪĿǰû��Ҫ	*/
#include <stdlib.h>
//#include <assert.h>

typedef struct SqString{
	char* ch;		// ����ַ�������
	int length;		// �ַ�����ǰ����
	int strSize;	// �ַ����ַ�����('\0'��������)
}SqString;

// BF�㷨���ִ�λ��
// SΪ���� TΪģʽ(�ִ�) posΪ��ʼ���ҵ�λ�ã�����ֵΪ�Ӵ���һ��Ԫ�����������±�
int index_BF(SqString* S,SqString* T,int pos);
// KMP�㷨���ִ�λ��
// SΪ���� TΪģʽ(�ִ�) posΪ��ʼ���ҵ�λ�ã�����ֵΪ�Ӵ���һ��Ԫ�����������±�
int index_KMP(SqString* S,SqString* T,int pos);

#endif