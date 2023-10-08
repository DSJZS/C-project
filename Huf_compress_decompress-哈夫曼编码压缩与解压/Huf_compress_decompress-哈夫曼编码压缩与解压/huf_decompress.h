#ifndef __HUF_DECOMPRESS_H__
#define __HUF_DECOMPRESS_H__

/*	��ѹ	*/

#include "FreqList.h"	/*	struct *FreqList - Freq			func ReadFreqList*/
#include "error.h"	/*	enum Status	- func ConfirmError*/
#include "FileHead.h"	/*	struct FileHead			func InitFileHead - DestroyFileHead*/
#include "memsize.h"	/*	define	FILEMAXSIZE	*/
#include "mark.h"	/*	define MARK	*/
#include <stdio.h> /*	func fopen - fclose - fgetc - feof - ferror - fwrite	*/

/*	�жϱ�ʶ
������
mark1 �� mark2 Ϊ������ű�ʶ���ַ���
����ֵ��
OK - ��ʾ����
WRONGMARK - ��ʶ����
*/
Status ConfirmMark(char* mark1,char* mark2);

/*	�ж�����
������
pwd1 �� pwd Ϊ��������
����ֵ��
OK - ��ʾ����
WRONGPWD - �������
*/
Status ConfirmPwd(unsigned int pwd1,unsigned int pwd2);

/*	������ѹ�ļ�
������
pfIn - ѹ�������ļ�ָ��
FL - �ַ�Ƶ���б�
destfile - ��ѹ�����ļ�������
����ֵ��
OK - ��ʾ����
UNKNOW - δ֪����
*/
Status ReadCompressFile(FILE* pfIn,FreqList FL,char* destfile);

/*	�����������ѹ
�βΣ�
srcfile - Ŀ���ļ���+��׺ �ַ���
pwd - ����������
����ֵ��
OK - ��ʾ����
OVERFLOW - ��ʾ��̬�ڴ�ռ俪��ʧ��
NOFOUND - ��ʾĿǰ�ļ�δ�ҵ�
UNKNOW - ��ʾδ֪����
WRONGMARK - ��ʶ����
WRONGPWD - �������
*/
Status HufDecompress(char srcfile[FILENAMEMAXSIZE],unsigned int pwd);

/*	��ѹ
�βΣ�
srcfile - Ŀ���ļ���+��׺ �ַ���
pwd - ����������
����ֵ��
OK - ��ʾ����
OVERFLOW - ��ʾ��̬�ڴ�ռ俪��ʧ��
NOFOUND - ��ʾĿǰ�ļ�δ�ҵ�
UNKNOW - ��ʾδ֪����
WRONGMARK - ��ʶ����
WRONGPWD - �������
*/
Status Decompress(char srcfile[FILENAMEMAXSIZE],unsigned int pwd);

#endif