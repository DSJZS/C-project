#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"
// ��ʼ��
void InitContact(struct Contact* ps)
{
	memset(ps->data, 0 ,sizeof(ps->data));
	ps->num = 0;
}
// ����
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
		printf("�������\n");
	}
}
// ɾ��
void DelContact(struct Contact* ps)
{
	char DelName[MAX_NAME] = {0};
	int i = 0;
	if(ps->num == 0)
	{
		printf("��ǰͨѶ¼Ϊ�գ�����Ӻ�����Ϣ\n");
		return;
	}
	printf("����ɾ����������\n:>");
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
			printf("ɾ���ɹ�\n");
			return;
		}
	}
	if(i == ps->num)
		printf("ɾ��ʧ�ܣ�ԭ�򣺲��޴���\n");
}
// ����
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
		printf("��ǰͨѶ¼Ϊ�գ�����Ӻ�����Ϣ\n");
		return;
	}
	printf("�����������\n:>");
	scanf("%s", SearchName);
	pos = find_by_name(ps,SearchName);
	
	if(pos == -1)
		printf("���޴���\n");
	else
	{
		printf("%20s\t%4s\t%5s\t%12s\t%20s\t%s\n","����","����","�Ա�","�绰","��ַ","�������");
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
// �޸�
void ModifyContact(struct Contact* ps)
{
	int pos = 0;
	char input = 0;
	int tmp = ps->num;
	char ModifyName[MAX_NAME] = {0};
	if(ps->num == 0)
	{
		printf("��ǰͨѶ¼Ϊ�գ�����Ӻ�����Ϣ\n");
		return;
	}
	printf("������Ҫ�޸ĺ��ѵ�����\n:>");
	scanf("%s", ModifyName);
	pos = find_by_name(ps,ModifyName);
	if(pos == -1)
	{
		printf("���޴���\n");
		return;
	}
	else
	{
		do
		{
			while(getchar() != '\n');
			printf("�Ƿ��޸ģ�����(y/n)\n:>");
			scanf("%c", &input);
			switch(input)
			{
			case 'y':
			case 'Y':
				ps->num = pos;
				AddContact(ps);
				ps->num = tmp;
				printf("���޸�\n");
				return;
				break;
			case 'n':
			case 'N':
				printf("��ȡ��\n");
				return;
				break;
			}
		}while(1);
	}
}
// ��ʾ
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
// ����
void SortContactMenu()	// ��ʾ�˵�
{
	printf("------------------------------\n");
	printf("* 0.ȡ������				  \n");
	printf("* 1.����������				  \n");
	printf("* 2.����������				  \n");
	printf("* 3.���Ա�����	  			  \n");
	printf("* 4.�����ʱ������			  \n");
	printf("------------------------------\n");
	printf("��������ѡ��(0-4)\n:>");
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
	int input = 0;	// ��ż���������Ϣ
	if(ps->num == 0)
	{
		printf("��ǰͨѶ¼Ϊ�գ�����Ӻ�����Ϣ\n");
		return;
	}
	do
	{
		SortContactMenu();
		scanf("%d", &input);
		switch(input)
		{
		case SORT_CANCLE:
			printf("�ɹ�ȡ������\n");
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
			printf("�������������0-4������ѡ��\n");
			break;
		}
		system("pause");
		system("cls");
	}while(input);
}



