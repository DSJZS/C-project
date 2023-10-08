#ifndef __HUFNDOE_H__
#define __HUFNDOE_H__

/*	�ַ�Ƶ���б�	*/


#include "error.h"	/*	enum Status			func ConfirmError*/
#include "memsize.h"	/*	func get_file_size	*/
#include <stdlib.h>	/*	func malloc - free	*/
#include <stdio.h> /*	func fopen - fclose - fgetc - feof - ferror	*/


//	����ַ���Ƶ��
typedef struct CharInfo{
	char c;		//	�ַ�
	long long freq;	//	�ַ���Ƶ��
}CharInfo;

//	��������
typedef struct Freq{
	CharInfo cInfo;	//	����ַ�����Ƶ��
	int parent,lch,rch;	//	˫�ף����Һ����±�
}Freq,*FreqList;

/*	����Ŀ���ļ��������ַ�Ƶ�ʱ�
�βΣ�
FL - ��Ҫ�������ַ�Ƶ�ʵ��б�(��������)
srcfile - Ŀ���ļ����ַ���
*count - ��¼�ַ�����
����ֵ��
OK - ��ʾ����
OVERFLOW - ��ʾ��̬�ڴ�ռ俪��ʧ��
NOFOUND - ��ʾĿǰ�ļ�δ�ҵ�
UNKNOW - ��ʾδ֪����
*/
Status CreateFreqList(FreqList* FL,char* srcfile, int* count);

/*	��ѹ�����ж�ȡ�ַ�Ƶ���б�(��������)
����;
FL - �����ȡ���ݵ��ַ�Ƶ�ʵ��б�(��������)
pfIn - ѹ�������ļ�ָ��
count - ��¼�ַ�����
����ֵ��
OK - ��ʾ����
OVERFLOW - ��ʾ��̬�ڴ�ռ俪��ʧ��
UNKNOW - ��ʾδ֪����
*/
Status ReadFreqList(FreqList* FL,FILE* pfIn, int count);

/*	�����ַ�Ƶ�ʱ�	
�βΣ�
FL - ��Ҫ���ٵ��ַ�Ƶ�ʵ��б�(��������)
����ֵ��
��
*/
void DestroyFreqList(FreqList FL);



#endif