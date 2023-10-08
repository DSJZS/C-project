#include "error.h"

int ConfirmError(Status error)
{
	switch(error)
	{
	case OK:
		return 0;
	case OVERFLOW:
		printf("内存空间已满\n");
		break;
	case NOFOUND:
		printf("未找到文件\n");
		break;
	case LONGNAME:
		printf("文件名过长，请将其缩短\n");
		break;
	case WRONGPWD:
		printf("错误的密码\n");
		break;
	case WRONGMARK:
		printf("错误的文件标记，文件压缩格式不匹配，可能不是该格式压缩文件\n");
		break;
	case UNKNOW:
	default:
		perror("未知错误，由编译器判断得出：");
		break;
	}
	return 1;
}