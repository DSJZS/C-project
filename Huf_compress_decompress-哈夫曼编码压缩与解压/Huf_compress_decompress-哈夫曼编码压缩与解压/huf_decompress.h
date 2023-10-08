#ifndef __HUF_DECOMPRESS_H__
#define __HUF_DECOMPRESS_H__

/*	解压	*/

#include "FreqList.h"	/*	struct *FreqList - Freq			func ReadFreqList*/
#include "error.h"	/*	enum Status	- func ConfirmError*/
#include "FileHead.h"	/*	struct FileHead			func InitFileHead - DestroyFileHead*/
#include "memsize.h"	/*	define	FILEMAXSIZE	*/
#include "mark.h"	/*	define MARK	*/
#include <stdio.h> /*	func fopen - fclose - fgetc - feof - ferror - fwrite	*/

/*	判断标识
参数：
mark1 与 mark2 为两个存放标识的字符串
返回值：
OK - 表示正常
WRONGMARK - 标识错误
*/
Status ConfirmMark(char* mark1,char* mark2);

/*	判断密码
参数：
pwd1 与 pwd 为两个数字
返回值：
OK - 表示正常
WRONGPWD - 密码错误
*/
Status ConfirmPwd(unsigned int pwd1,unsigned int pwd2);

/*	创建解压文件
参数：
pfIn - 压缩包的文件指针
FL - 字符频率列表
destfile - 解压出的文件的名字
返回值：
OK - 表示正常
UNKNOW - 未知错误
*/
Status ReadCompressFile(FILE* pfIn,FreqList FL,char* destfile);

/*	哈夫曼编码解压
形参：
srcfile - 目标文件名+后缀 字符串
pwd - 纯数字密码
返回值：
OK - 表示正常
OVERFLOW - 表示动态内存空间开辟失败
NOFOUND - 表示目前文件未找到
UNKNOW - 表示未知错误
WRONGMARK - 标识错误
WRONGPWD - 密码错误
*/
Status HufDecompress(char srcfile[FILENAMEMAXSIZE],unsigned int pwd);

/*	解压
形参：
srcfile - 目标文件名+后缀 字符串
pwd - 纯数字密码
返回值：
OK - 表示正常
OVERFLOW - 表示动态内存空间开辟失败
NOFOUND - 表示目前文件未找到
UNKNOW - 表示未知错误
WRONGMARK - 标识错误
WRONGPWD - 密码错误
*/
Status Decompress(char srcfile[FILENAMEMAXSIZE],unsigned int pwd);

#endif