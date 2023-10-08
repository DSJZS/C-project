#ifndef __HUFCODELIST_H__
#define __HUFCODELIST_H__

/*	�ַ����������б�	*/

#include "FreqList.h"	/*	struct *FreqList - Freq	*/
#include "error.h"	/*	enum Status			func ConfirmError*/
#include <stdlib.h>	/*	func malloc - calloc - free	*/
#include <string.h> /*	func strcpy	*/

typedef struct HufCode{
	unsigned char c;	// �ַ�
	char* hcode;	//	����������
}HufCode,*HufCodeList;

/*	���������������
�βΣ�
FL - ��Ÿ����ַ�Ƶ�ʵ��б�(��������)
*HCL - ��Ÿ����ַ���������������� 
count - ��¼�ַ����������
����ֵ��
OK - ��ʾ����
OVERFLOW - ��ʾ��̬�ڴ�ռ俪��ʧ��
*/
Status CreateHufCodeList(FreqList FL,HufCodeList* HCL,int count);

/*	���ٹ����������
�βΣ�
FL - ��Ÿ����ַ�Ƶ�ʵ��б�(��������)
count - ��¼�ַ����������
����ֵ��
��
*/
void DestroyHufCodeList(HufCodeList HCL,int count);

#endif