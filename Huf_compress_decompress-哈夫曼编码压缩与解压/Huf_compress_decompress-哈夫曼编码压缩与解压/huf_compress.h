#ifndef __HUF_COMPRESS_H__
#define __HUF_COMPRESS_H__

/*	ѹ��	*/

#include "FreqList.h"	/*	struct *FreqList - Freq			func CreateFreqList - DestroyFreqList*/
#include "error.h"	/*	enum Status			func ConfirmError*/
#include "HufCodeList.h" /*	struct *HufCodeList - HufCode		func CreateHufCodeList - DestroyHufCodeList*/
#include "FileHead.h"	/*	struct FileHead			func InitFileHead - DestroyFileHead*/
#include "memsize.h"	/*	define	FILEMAXSIZE*/
#include <stdio.h> /*	func fopen - fclose - fgetc - feof - ferror - fprintf - fwrite	*/
#include <string.h> /*	func strlen - strcpy(debug) - strcat	*/





/*	����ѹ���ļ�	
�βΣ�
HCL - ��Ÿ����ַ�������������б�
count - ��¼�ַ�����
pwd - ѹ���ļ�����
����ֵ��
OK - ��ʾ����
NOFOUND - ��ʾĿǰ�ļ�δ�ҵ�
UNKNOW - ��ʾδ֪����
*/
Status CreatingCompressFile(FreqList FL,HufCodeList HCL,int count, char* srcfile,char* destfile,unsigned int pwd);

/*����������ѹ��
�βΣ�
srcfile - Ŀ���ļ���+��׺ �ַ���
destfile - ѹ�����ļ����ַ���
pwd - ����������
����ֵ��
OK - ��ʾ����
OVERFLOW - ��ʾ��̬�ڴ�ռ俪��ʧ��
NOFOUND - ��ʾĿǰ�ļ�δ�ҵ�
UNKNOW - ��ʾδ֪����
*/
Status HufCompress(char srcfile[FILENAMEMAXSIZE],char destfile[FILENAMEMAXSIZE],int pwd);


/*ѹ��
�βΣ�
srcfile - Ŀ���ļ���+��׺ �ַ���
destfile - ѹ�����ļ����ַ���
pwd - ����������
����ֵ��
OK - ��ʾ����
OVERFLOW - ��ʾ��̬�ڴ�ռ俪��ʧ��
NOFOUND - ��ʾĿǰ�ļ�δ�ҵ�
UNKNOW - ��ʾδ֪����
*/
Status Compress(char srcfile[FILENAMEMAXSIZE],char destfile[FILENAMEMAXSIZE],int pwd);

#endif