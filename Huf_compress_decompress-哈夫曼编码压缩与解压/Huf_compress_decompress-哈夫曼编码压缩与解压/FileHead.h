#ifndef __FILEHEAD_H__
#define __FILEHEAD_H__


/*	压缩文件头，压缩时作为解压时的标识放入文件头部	
	同时决定了压缩文件的后缀	*/

#include "memsize.h"	/*	define	FILEMAXSIZE*/
#include "error.h"	/*	enum Status	*/
#include "mark.h"	/*	define MARK	*/
#include <stdlib.h>	/*	func malloc - free	*/
#include <string.h> /*	func strcpy	*/

typedef struct FileHead{
	
	
	char mark[MARKMAXSIZE];	/*	压缩文件标识和后缀，本程序默认为"FR" (freshman的缩写)，
					可在 huf_compress.c 文件下的InitFileHead函数中修改 */
	char srcfile[FILENAMEMAXSIZE];	//	文件压缩前的文件名和后缀
	unsigned int password;	//	压缩文件密码(纯数字)
	int count;	//	记载字符数量
}FileHead;

/*	初始化文件头
参数：
fh - 需要初始化的文件头的指针
pwd - 密码
srcfile - 被压缩文件名
count - 被压缩文件中字符种类个数
返回值：
OK - 没问题
*/
Status InitFileHead(FileHead* fh, unsigned int pwd,char srcfile[FILENAMEMAXSIZE], int count);
/*	销毁文件头
参数：
fh - 需要销毁的文件头的指针
返回值：
无
*/
void DestroyFileHead(FileHead* fh);

#endif