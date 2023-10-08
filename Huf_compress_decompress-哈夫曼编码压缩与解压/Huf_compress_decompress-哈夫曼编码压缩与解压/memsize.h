#ifndef __MEMSIZE_H__
#define __MEMSIZE_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define FILENAMEMAXSIZE 256	//	文件名最大长度
#define MARKMAXSIZE 8	//	文件标识最大长度

long get_file_size(FILE *stream);



#endif