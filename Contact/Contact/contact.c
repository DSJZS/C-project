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
		ps->num++;
		printf("输入完毕，已添加\n");
	}
}