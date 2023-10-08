#define _CRT_SECURE_NO_WARNINGS 1

#include "FileHead.h"

//	初始化文件头
Status InitFileHead(FileHead* fh, unsigned int pwd,char srcfile[FILENAMEMAXSIZE], int count)
{
	char mark[] = MARK;
	strcpy(fh->mark,mark);
	fh->password = pwd;
	fh->count = count;
	strcpy(fh->srcfile,srcfile);
	return OK;
}
//	销毁文件头
void DestroyFileHead(FileHead* fh)
{
	fh->password = 0;
}