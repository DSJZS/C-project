#ifndef __FILEHEAD_H__
#define __FILEHEAD_H__


/*	ѹ���ļ�ͷ��ѹ��ʱ��Ϊ��ѹʱ�ı�ʶ�����ļ�ͷ��	
	ͬʱ������ѹ���ļ��ĺ�׺	*/

#include "memsize.h"	/*	define	FILEMAXSIZE*/
#include "error.h"	/*	enum Status	*/
#include "mark.h"	/*	define MARK	*/
#include <stdlib.h>	/*	func malloc - free	*/
#include <string.h> /*	func strcpy	*/

typedef struct FileHead{
	
	
	char mark[MARKMAXSIZE];	/*	ѹ���ļ���ʶ�ͺ�׺��������Ĭ��Ϊ"FR" (freshman����д)��
					���� huf_compress.c �ļ��µ�InitFileHead�������޸� */
	char srcfile[FILENAMEMAXSIZE];	//	�ļ�ѹ��ǰ���ļ����ͺ�׺
	unsigned int password;	//	ѹ���ļ�����(������)
	int count;	//	�����ַ�����
}FileHead;

/*	��ʼ���ļ�ͷ
������
fh - ��Ҫ��ʼ�����ļ�ͷ��ָ��
pwd - ����
srcfile - ��ѹ���ļ���
count - ��ѹ���ļ����ַ��������
����ֵ��
OK - û����
*/
Status InitFileHead(FileHead* fh, unsigned int pwd,char srcfile[FILENAMEMAXSIZE], int count);
/*	�����ļ�ͷ
������
fh - ��Ҫ���ٵ��ļ�ͷ��ָ��
����ֵ��
��
*/
void DestroyFileHead(FileHead* fh);

#endif