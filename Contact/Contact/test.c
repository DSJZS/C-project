#define _CRT_SECURE_NO_WARNINGS 1


#include"contact.h"

void menu()	// 显示菜单
{
	printf("------------------------------\n");
	printf("* 0.退出通讯录				  \n");
	printf("* 1.存放好友的信息			  \n");
	printf("* 2.增加好友信息			  \n");
	printf("* 3.删除指定名字的好友信息    \n");
	printf("* 4.查找好友信息  			  \n");
	printf("* 5.修改好友信息			  \n");
	printf("* 6.显示好友信息			  \n");
	printf("* 7.排序好友信息			  \n");
	printf("------------------------------\n");
	printf("输入数字选择(0-7)\n:>");
}

int main()
{
	int input = 0;	// 存放键盘输入信息
	struct Contact con;	// 创建通讯录
	
	InitContact(&con);

	do
	{
		menu();
		scanf("%d", &input);
		switch(input)
		{
		case 0:
			printf("成功退出\n");
			break;
		case 1:
			AddContact(&con);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			ShowConact(&con);
			break;
		case 7:
			break;
		default:
			printf("输入错误，请输入0-7的数字选项\n");
			break;
		}
		system("pause");
		system("cls");
	}while(input);
	return 0;
}