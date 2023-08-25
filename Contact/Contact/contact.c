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
		time_t seconds;
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
		time(&seconds);
		ps->data[ps->num].time = localtime(&seconds);
		ps->num++;
		printf("������ϣ������\n");
	}
}

void ShowConact(const struct Contact* ps)
{
	if(ps->num == 0)
	{
		printf("��ǰͨѶ¼Ϊ�գ�����Ӻ�����Ϣ\n");
	}
	else
	{
		int i = 0;
		printf("%20s\t%4s\t%5s\t%12s\t%20s\t%s\n","����","����","�Ա�","�绰","��ַ","�������");
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

