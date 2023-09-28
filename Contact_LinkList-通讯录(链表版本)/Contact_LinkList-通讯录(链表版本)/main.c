#define _CRT_SECURE_NO_WARNINGS 1

#include "Contact_LinkList.h"

void menu(const Contact pC)	// 显示菜单
{
	printf("------------------------------\n");
	printf("* 0.退出通讯录				  \n");
	printf("* 1.增加好友信息			  \n");
	printf("* 2.删除指定名字的好友信息    \n");
	printf("* 3.查找好友信息  			  \n");
	printf("* 4.修改好友信息			  \n");
	printf("* 5.显示好友信息			  \n");
	printf("* 6.排序好友信息			  \n");
	printf("------------------------------\n");
	printf("当前好友数量: %4d\n",pC->age);
	printf("输入数字选择(0-7)\n:>");
}

int main()
{
	int input = 0;	// 存放键盘输入信息
	Contact C;	// 创建通讯录

	InitContact(&C);

	do
	{
		menu(C);
		scanf("%d", &input);
		switch(input)
		{
		case EXIT:
			CloseContact(C);
			printf("成功退出\n");
			break;
		case ADD:
			AddContact(C);
			break;
		case DEL:
			DelContact(C);
			break;
		case SEARCH:
			SearchContact(C);
			break;
		case MODIFY:
			ModifyContact(C);
			break;
		case SHOW:
			ShowConact(C);
			break;
		case SORT:
			SortContact(C);
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
