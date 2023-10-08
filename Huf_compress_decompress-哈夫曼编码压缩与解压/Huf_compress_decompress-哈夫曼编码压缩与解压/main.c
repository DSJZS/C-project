#define _CRT_SECURE_NO_WARNINGS 1

#include "huf_compress.h"	/*	压缩	*/
#include "huf_decompress.h" /*	解压	*/
#include <stdlib.h>	/*	func system	*/

void menu()
{
	printf("==================FR压缩===================\n");
	printf("||    按 0 关闭程序  ━━━∑0□0*川━	 ||\n");
	printf("||    按 1 开始压缩  (￣ε(#￣) Σ	 ||\n");
	printf("||    按 2 开始解压  ε=ε=(ノ≧W≦)ノ	 ||\n");
	printf("==================FR压缩===================\n");
	printf("\n输入>:");
}
int main()
{
	int input = 0;
	char srcfile[FILENAMEMAXSIZE] = {0};
	char destfile[FILENAMEMAXSIZE] = {0};
	int pwd = 0;

	do{
		menu();
		scanf("%d", &input);
		switch(input)
		{
		case 0:
			printf("退出成功\n");
			break;
		case 1:
			printf("请输入要压缩的文件(文件名和后缀均要写全，且该文件要在当前路径下)\n >:");
			scanf("%s", srcfile);
			printf("请输入产生的压缩包的文件名(后缀不必添加)\n >:");
			scanf("%s", destfile);
			printf("请输入压缩包密码\n >:");
			scanf("%d", &pwd);
			if(OK == Compress(srcfile,destfile,pwd))
				printf("压缩成功\\OVO/\n");
			else
				printf("压缩失败QAQ\n");
			break;
		case 2:
			printf("请输入要解压的压缩包(文件名和后缀均要写全，且该文件要在当前路径下)\n >:");
			scanf("%s", srcfile);
			printf("请输入压缩包密码\n >:");
			scanf("%d", &pwd);
			if(OK == Decompress(srcfile,pwd))
				printf("解压成功\\OVO/\n");
			else
				printf("解压失败QAQ\n");
			break;
		default:
			printf("选项输入错误\n");
			break;
		}
		system("pause");
		system("cls");
	}while(input);
	
	return 0;
}