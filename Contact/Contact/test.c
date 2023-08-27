#define _CRT_SECURE_NO_WARNINGS 1


#include"contact.h"

void menu(const struct Contact* ps)	// 显示菜单
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
	printf("当前好友数量(%4d/%4d)\n",ps->num,MAX_PEO);
	// printf("test:%d\n",ps->maxNum);
	printf("输入数字选择(0-7)\n:>");
}

int main()
{
	int input = 0;	// 存放键盘输入信息
	struct Contact con;	// 创建通讯录
	
	InitContact(&con);

	do
	{
		menu(&con);
		scanf("%d", &input);
		switch(input)
		{
		case EXIT:
			printf("成功退出\n");
			break;
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowConact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		default:
			printf("输入错误，请输入0-7的数字选项\n");
			break;
		}
		system("pause");
		system("cls");
	}while(input);
	free(con.data);
	con.data = NULL;
	return 0;
}