#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"
// 初始化
void InitContact(struct Contact* ps)
{
	memset(ps->data, 0 ,sizeof(ps->data));
	ps->num = 0;
}
// 增加
void AddContact(struct Contact* ps)
{
	if(ps->num == MAX_PEO)
		printf("通讯录已满，无法存放新的好友的信息\n");
	else
	{
		time_t seconds;
		printf("(1/5)请输入名字:>");
		scanf("%s", (ps->data[ps->num].name) );
		printf("(2/5)请输入年龄:>");
		scanf("%d",&(ps->data[ps->num].age) );
		printf("(3/5)请输入性别:>");
		scanf("%s", (ps->data[ps->num].sex) );
		printf("(4/5)请输入电话:>");
		scanf("%s", (ps->data[ps->num].tele) );
		printf("(5/5)请输入地址:>");
		scanf("%s", (ps->data[ps->num].addr) );
		time(&seconds);
		ps->data[ps->num].time = localtime(&seconds);
		ps->num++;
		printf("输入完毕\n");
	}
}
// 删除
void DelContact(struct Contact* ps)
{
	char DelName[MAX_NAME] = {0};
	int i = 0;
	if(ps->num == 0)
	{
		printf("当前通讯录为空，请添加好友信息\n");
		return;
	}
	printf("输入删除好友名字\n:>");
	scanf("%s", DelName);
	for(i=0;i<ps->num;i++)
	{
		if( !(strcmp(ps->data[i].name,DelName)) )
		{

			for(;i<ps->num-1;i++)
			{
				ps->data[i] = ps->data[i+1];
			}
			ps->num--;
			printf("删除成功\n");
			return;
		}
	}
	if(i == ps->num)
		printf("删除失败，原因：查无此人\n");
}
// 查找
int find_by_name(const struct Contact* ps,char* SearchName)
{
	int i = 0;
	for(i=0;i<ps->num;i++)
	{
		if( !(strcmp(ps->data[i].name,SearchName)) )
		{
			return i;
		}
	}
	return -1;
}
void SearchContact(const struct Contact* ps)
{
	char SearchName[MAX_NAME] = {0};
	int pos = 0;
	if(ps->num == 0)
	{
		printf("当前通讯录为空，请添加好友信息\n");
		return;
	}
	printf("输入好友姓名\n:>");
	scanf("%s", SearchName);
	pos = find_by_name(ps,SearchName);
	
	if(pos == -1)
		printf("查无此人\n");
	else
	{
		printf("%20s\t%4s\t%5s\t%12s\t%20s\t%s\n","名字","年龄","性别","电话","地址","添加日期");
		printf("%20s\t%4d\t%5s\t%12s\t%20s\t%d.%2d.%2d\n",
			ps->data[pos].name,
			ps->data[pos].age,
			ps->data[pos].sex,
			ps->data[pos].tele,
			ps->data[pos].addr,
			ps->data[pos].time->tm_year+1900,
			ps->data[pos].time->tm_mon+1,
			ps->data[pos].time->tm_mday);
	}
	
}
// 修改
void ModifyContact(struct Contact* ps)
{
	int pos = 0;
	char input = 0;
	int tmp = ps->num;
	char ModifyName[MAX_NAME] = {0};
	if(ps->num == 0)
	{
		printf("当前通讯录为空，请添加好友信息\n");
		return;
	}
	printf("请输入要修改好友的姓名\n:>");
	scanf("%s", ModifyName);
	pos = find_by_name(ps,ModifyName);
	if(pos == -1)
	{
		printf("查无此人\n");
		return;
	}
	else
	{
		do
		{
			while(getchar() != '\n');
			printf("是否修改？输入(y/n)\n:>");
			scanf("%c", &input);
			switch(input)
			{
			case 'y':
			case 'Y':
				ps->num = pos;
				AddContact(ps);
				ps->num = tmp;
				printf("已修改\n");
				return;
				break;
			case 'n':
			case 'N':
				printf("已取消\n");
				return;
				break;
			}
		}while(1);
	}
}
// 显示
void ShowConact(const struct Contact* ps)
{
	if(ps->num == 0)
	{
		printf("当前通讯录为空，请添加好友信息\n");
	}
	else
	{
		int i = 0;
		printf("%20s\t%4s\t%5s\t%12s\t%20s\t%s\n","名字","年龄","性别","电话","地址","添加日期");
		for(i=0;i<ps->num;i++)
		{
			printf("%20s\t%4d\t%5s\t%12s\t%20s\t%d.%2d.%2d\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].addr,
				ps->data[i].time->tm_year+1900,
				ps->data[i].time->tm_mon+1,
				ps->data[i].time->tm_mday);
		}
	}
}
// 排序
void SortContactMenu()	// 显示菜单
{
	printf("------------------------------\n");
	printf("* 0.取消排序				  \n");
	printf("* 1.按名字排序				  \n");
	printf("* 2.按年龄排序				  \n");
	printf("* 3.按性别排序	  			  \n");
	printf("* 4.按添加时间排序			  \n");
	printf("------------------------------\n");
	printf("输入数字选择(0-4)\n:>");
}
int sort_by_name(const void* ps1, const void* ps2)
{
	return strcmp(((struct PeoInfo*)ps1)->name,((struct PeoInfo*)ps2)->name);
}
int sort_by_age(const void* ps1, const void* ps2)
{
	return ((struct PeoInfo*)ps1)->age - ((struct PeoInfo*)ps2)->age;
}
int sort_by_sex(const void* ps1, const void* ps2)
{
	return strcmp(((struct PeoInfo*)ps1)->sex,((struct PeoInfo*)ps2)->sex);
}
int sort_by_time(const void* ps1, const void* ps2)
{
	int ret = 0;
	if(!(ret = (((struct PeoInfo*)ps1)->time->tm_year-((struct PeoInfo*)ps2)->time->tm_year)))
	{
		if(!(ret = (((struct PeoInfo*)ps1)->time->tm_mon-((struct PeoInfo*)ps2)->time->tm_mon)))
		{
			ret = (((struct PeoInfo*)ps1)->time->tm_mday-((struct PeoInfo*)ps2)->time->tm_mday);
			return ret;
		}
		else
			return ret;
	}
	else
		return ret;
}
void SortContact(struct Contact* ps)
{
	int input = 0;	// 存放键盘输入信息
	if(ps->num == 0)
	{
		printf("当前通讯录为空，请添加好友信息\n");
		return;
	}
	do
	{
		SortContactMenu();
		scanf("%d", &input);
		switch(input)
		{
		case SORT_CANCLE:
			printf("成功取消排序\n");
			return;
		case SORT_BY_NAME:
			qsort(ps->data,ps->num,sizeof(ps->data[0]),sort_by_name);
			return;
		case SORT_BY_AGE:
			qsort(ps->data,ps->num,sizeof(ps->data[0]),sort_by_age);
			return;
		case SORT_BY_SEX:
			qsort(ps->data,ps->num,sizeof(ps->data[0]),sort_by_sex);
			return;
		case SORT_BY_TIME:
			qsort(ps->data,ps->num,sizeof(ps->data[0]),sort_by_time);
			return;
		default:
			printf("输入错误，请输入0-4的数字选项\n");
			break;
		}
		system("pause");
		system("cls");
	}while(input);
}



