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
		printf("ͨѶ¼�������޷�����µĺ��ѵ���Ϣ\n");
	else
	{
		printf("(1/5)����������:>");
		scanf("%s", (ps->data[ps->num].name) );
		printf("(2/5)����������:>");
		scanf("%d",&(ps->data[ps->num].age) );
		printf("(3/5)�������Ա�:>");
		scanf("%s", (ps->data[ps->num].sex) );
		printf("(4/5)������绰:>");
		scanf("%s", (ps->data[ps->num].tele) );
		printf("(5/5)�������ַ:>");
		scanf("%s", (ps->data[ps->num].addr) );
		ps->num++;
		printf("������ϣ������\n");
	}
}