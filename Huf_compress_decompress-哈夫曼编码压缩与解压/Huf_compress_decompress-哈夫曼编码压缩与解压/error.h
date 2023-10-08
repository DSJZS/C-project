#ifndef __ERROR_H__
#define __ERROR_H__

/*	各种错误标识，用来表示各种错误	*/

// 该宏用于启动调试
//	#define _DEBUG_


#include <stdio.h>	/*	func printf	*/

typedef enum Status{
	OK,
	OVERFLOW,
	UNKNOW,
	NOFOUND,
	LONGNAME,
	WRONGPWD,
	WRONGMARK
}Status;


/*确认错误，如果有错误打印错误信息并且返回 1，否则返回 0	
形参：
error - 错误码
返回值：
如果有错误，返回1
没有返回 0
*/
int ConfirmError(Status error);

#endif;