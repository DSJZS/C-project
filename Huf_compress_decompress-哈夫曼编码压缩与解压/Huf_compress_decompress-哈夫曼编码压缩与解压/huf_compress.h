#ifndef __HUF_COMPRESS_H__
#define __HUF_COMPRESS_H__

/*	压缩	*/

#include "FreqList.h"	/*	struct *FreqList - Freq			func CreateFreqList - DestroyFreqList*/
#include "error.h"	/*	enum Status			func ConfirmError*/
#include "HufCodeList.h" /*	struct *HufCodeList - HufCode		func CreateHufCodeList - DestroyHufCodeList*/
#include "FileHead.h"	/*	struct FileHead			func InitFileHead - DestroyFileHead*/
#include "memsize.h"	/*	define	FILEMAXSIZE*/
#include <stdio.h> /*	func fopen - fclose - fgetc - feof - ferror - fprintf - fwrite	*/
#include <string.h> /*	func strlen - strcpy(debug) - strcat	*/





/*	产生压缩文件	
形参：
HCL - 存放各个字符哈夫曼编码的列表
count - 记录字符个数
pwd - 压缩文件密码
返回值：
OK - 表示正常
NOFOUND - 表示目前文件未找到
UNKNOW - 表示未知错误
*/
Status CreatingCompressFile(FreqList FL,HufCodeList HCL,int count, char* srcfile,char* destfile,unsigned int pwd);

/*哈夫曼编码压缩
形参：
srcfile - 目标文件名+后缀 字符串
destfile - 压缩包文件名字符串
pwd - 纯数字密码
返回值：
OK - 表示正常
OVERFLOW - 表示动态内存空间开辟失败
NOFOUND - 表示目前文件未找到
UNKNOW - 表示未知错误
*/
Status HufCompress(char srcfile[FILENAMEMAXSIZE],char destfile[FILENAMEMAXSIZE],int pwd);


/*压缩
形参：
srcfile - 目标文件名+后缀 字符串
destfile - 压缩包文件名字符串
pwd - 纯数字密码
返回值：
OK - 表示正常
OVERFLOW - 表示动态内存空间开辟失败
NOFOUND - 表示目前文件未找到
UNKNOW - 表示未知错误
*/
Status Compress(char srcfile[FILENAMEMAXSIZE],char destfile[FILENAMEMAXSIZE],int pwd);

#endif