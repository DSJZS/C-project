#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

void InitContact(struct Contact* ps)
{
	memset(ps->data, 0 ,sizeof(ps->data));
	ps->num = 0;
}

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
		printf("输入完毕，已添加\n");
	}
}

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

