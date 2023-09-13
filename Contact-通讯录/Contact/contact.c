#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"
// ���Ҹ�����Ϣλ�÷������±�
static int find_by_name(const struct Contact* ps,char* SearchName)
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
// ����SortContact�������������Ϣ
static void sort_contact_menu()	// ��ʾ�˵�
{
	printf("------------------------------\n");
	printf("* 0.ȡ������				  \n");
	printf("* 1.����������				  \n");
	printf("* 2.����������				  \n");
	printf("* 3.���Ա�����	  			  \n");
	printf("------------------------------\n");
	printf("��������ѡ��(0-3)\n:>");
}
static int sort_by_name(const void* ps1, const void* ps2)
{
	return strcmp(((struct PeoInfo*)ps1)->name,((struct PeoInfo*)ps2)->name);
}
static int sort_by_age(const void* ps1, const void* ps2)
{
	return ((struct PeoInfo*)ps1)->age - ((struct PeoInfo*)ps2)->age;
}
static int sort_by_sex(const void* ps1, const void* ps2)
{
	return strcmp(((struct PeoInfo*)ps1)->sex,((struct PeoInfo*)ps2)->sex);
}
// ���ͨѶ¼�Ƿ���������
static int check_capacity(struct Contact* ps)
{
	if(ps->num == ps->capacity)
		return 1;
	else
		return 0;
}
// ��������
static void increase_capacity(struct Contact* ps)
{
	struct PeoInfo* ptr = NULL;
	if( (ps->capacity+PEO_ADD)>MAX_PEO )
		ptr = (struct PeoInfo*)realloc(ps->data,(MAX_PEO) * sizeof(struct PeoInfo));
	else
		ptr = (struct PeoInfo*)realloc(ps->data,(ps->capacity+PEO_ADD) * sizeof(struct PeoInfo));
	if(ptr == NULL)
	{
		printf("add error\n");
		return;
	}
	else
	{
		ps->data = ptr;
		ps->capacity += PEO_ADD;
	}
}
// ����ͨѶ¼
static void save_contact(struct Contact* ps)
{
	FILE* pfWrite = fopen("PeoInfo.txt","w");
	if(pfWrite == NULL)
	{
		printf("close fopen error\n");
		return;
	}
	else
	{
		int i = 0;
		for(i=0;i<(ps->num);i++)
		{
			fprintf(pfWrite, "%s %d %s %s %s\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].addr);
		}
	}
	fclose(pfWrite);
	pfWrite=NULL;
}
// ����ͨѶ¼
static void load_contact(struct Contact* ps)
{
	FILE* pfRead = fopen("PeoInfo.txt","r");
	if(pfRead == NULL)
	{
		printf("init fopen error\n");
		return;
	}
	else
	{
		while(EOF != fscanf(pfRead,"%s %d %s %s %s\n",
			ps->data[ps->num].name,
			&ps->data[ps->num].age,
			ps->data[ps->num].sex,
			ps->data[ps->num].tele,
			ps->data[ps->num].addr))
		{
			ps->num++;
			if( check_capacity(ps) )
				increase_capacity(ps);
		}
	}
	fclose(pfRead);
	pfRead=NULL;
}
// ��ʼ��
void InitContact(struct Contact* ps)
{
	struct PeoInfo* ptr = (struct PeoInfo*)malloc(PEO_INIT * sizeof(struct PeoInfo));
	
	if(ptr == NULL)
	{
		printf("init malloc error\n");
		return;
	}
	else
	{
		ps->data = ptr;
	}
	memset(ps->data, 0 ,(PEO_INIT * sizeof(struct PeoInfo)) );
	ps->num = 0;
	ps->capacity = PEO_INIT;
	load_contact(ps);
}
// ����
void AddContact(struct Contact* ps)
{
	if(ps->num == MAX_PEO)
		printf("ͨѶ¼�������޷�����µĺ��ѵ���Ϣ\n");
	else
	{
		if(check_capacity(ps))
		{
			increase_capacity(ps);
		}
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
		printf("�������\n");
	}
}
// ɾ��
void DelContact(struct Contact* ps)
{
	char DelName[MAX_NAME] = {0};
	int pos = 0;
	if(ps->num == 0)
	{
		printf("��ǰͨѶ¼Ϊ�գ�����Ӻ�����Ϣ\n");
		return;
	}
	printf("����ɾ����������\n:>");
	scanf("%s", DelName);
	pos = find_by_name(ps,DelName);
	if(pos == -1)
		printf("ɾ��ʧ�ܣ�ԭ�򣺲��޴���\n");
	else
	{
		struct PeoInfo* ptr = NULL;
		for(;pos< (ps->num-1) ;pos++)
		{
			ps->data[pos] = ps->data[pos+1];
		}
		ptr =(struct PeoInfo*)realloc(ps->data,(--(ps->num)) * sizeof(struct PeoInfo));
		if(ptr == NULL)
		{
			printf("del error\n");
			return;
		}
		else
		{
			ps->data = ptr;
			printf("ɾ���ɹ�\n");
		}
	}

			
}
// ����
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
		printf("%20s\t%4s\t%5s\t%12s\t%20s\n","����","����","�Ա�","�绰","��ַ");
		printf("%20s\t%4d\t%5s\t%12s\t%20s\n",
			ps->data[pos].name,
			ps->data[pos].age,
			ps->data[pos].sex,
			ps->data[pos].tele,
			ps->data[pos].addr);
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
		printf("%20s\t%4s\t%5s\t%12s\t%20s\n","����","����","�Ա�","�绰","��ַ");
		for(i=0;i<ps->num;i++)
		{
			printf("%20s\t%4d\t%5s\t%12s\t%20s\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].addr);
		}
	}
}
// ����
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
		sort_contact_menu();
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
		default:
			printf("�������������0-4������ѡ��\n");
			break;
		}
		system("pause");
		system("cls");
	}while(input);
}
// �ر�
void CloseContact(struct Contact* ps)
{
	save_contact(ps);
	

	free(ps->data);
	ps->data=NULL;
}


