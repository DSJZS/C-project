#define _CRT_SECURE_NO_WARNINGS 1

#include "FileHead.h"

//	��ʼ���ļ�ͷ
Status InitFileHead(FileHead* fh, unsigned int pwd,char srcfile[FILENAMEMAXSIZE], int count)
{
	char mark[] = MARK;
	strcpy(fh->mark,mark);
	fh->password = pwd;
	fh->count = count;
	strcpy(fh->srcfile,srcfile);
	return OK;
}
//	�����ļ�ͷ
void DestroyFileHead(FileHead* fh)
{
	fh->password = 0;
}