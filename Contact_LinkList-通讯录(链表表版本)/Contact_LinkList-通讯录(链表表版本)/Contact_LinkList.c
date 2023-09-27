#define _CRT_SECURE_NO_WARNINGS 1

#include "Contact_LinkList.h"

// ��ʾһ�����ѵ���Ϣ
static void ShowPeoInfo(const PeoInfoNode* PeoInfo)
{
			printf("%20s\t%4s\t%5s\t%12s\t%20s\n","����","����","�Ա�","�绰","��ַ");
			printf("%20s\t%4d\t%5s\t%12s\t%20s\n",
				PeoInfo->name,
				PeoInfo->age,
				PeoInfo->sex,
				PeoInfo->tele,
				PeoInfo->addr);
}

// �������ֲ���һ�����ѵ�λ��
static PeoInfoNode* FindPeoByName(Contact C, char FindName[MAX_NAME])
{
	C = C->next;
	while(C)
	{
		if( !( strcmp(C->name, FindName) ) )
		{
			return C;
		}
		C = C->next;
	}
	return NULL;
}

// ������ר����ʾ�˵�
static void sort_contact_menu()	
{
	printf("------------------------------\n");
	printf("* 0.ȡ������				  \n");
	printf("* 1.����������				  \n");
	printf("* 2.����������				  \n");
	printf("* 3.���Ա�����	  			  \n");
	printf("------------------------------\n");
	printf("��������ѡ��(0-3)\n:>");
}

// ������ר��ͨ������
static void PeoInfoSort(Contact C, int(*cmp)(PeoInfoNode* x, PeoInfoNode* y))
{
	int i = 0;
	PeoInfoNode* p = NULL;

	for( i=0; i < (C->age - 1) ; ++i )
	{
		int j = 0;
		p = C->next;
		for( j=0 ; j < (C->age - 1 - i) ; ++j )
		{
			if( cmp(p,p->next) > 0 )
			{
				char tmp_str[(MAX_NAME + MAX_SEX + MAX_TELE + MAX_ADDR)] = {0};
				int tmp_int = 0;

				strcpy(tmp_str,p->addr);
				strcpy(p->addr,p->next->addr);
				strcpy(p->next->addr,tmp_str);

				strcpy(tmp_str,p->name);
				strcpy(p->name,p->next->name);
				strcpy(p->next->name,tmp_str);

				strcpy(tmp_str,p->sex);
				strcpy(p->sex,p->next->sex);
				strcpy(p->next->sex,tmp_str);

				strcpy(tmp_str,p->tele);
				strcpy(p->tele,p->next->tele);
				strcpy(p->next->tele,tmp_str);

				tmp_int = p->age;
				p->age = p->next->age;
				p->next->age = tmp_int;
			}
			p = p->next;
		}
	}
}

// ������ר�ñȽϺ���
int sort_by_name(PeoInfoNode* x, PeoInfoNode* y)
{
	return strcmp(x->name,y->name);
}
int sort_by_age(PeoInfoNode* x, PeoInfoNode* y)
{
	return (x->age - y->age);
}
int sort_by_sex(PeoInfoNode* x, PeoInfoNode* y)
{
	return strcmp(x->sex,y->sex);
}

// ����ͨѶ¼������
static void save_contact(Contact C)
{
	FILE* pfWrite = fopen("PeoInfo.txt","w");
	if(!pfWrite)
	{
		printf("����ʧ��\n");
		return;
	}
	C = C->next;
	while(C)
	{
		fprintf(pfWrite, "%s %d %s %s %s\n",
			C->name,
			C->age,
			C->sex,
			C->tele,
			C->addr);
		C = C->next;
	}
	fclose(pfWrite);
	pfWrite = NULL;
}

// �ӱ��ؼ���ͨѶ¼
static void load_contact(Contact C)
{
	FILE* pfRead = fopen("PeoInfo.txt","r");
	PeoInfoNode *p,*q;
	if(pfRead == NULL)
	{
		printf("��ӭ�㣬���û�\n");
		return;
	}
	else
	{
		p = (PeoInfoNode*)malloc(sizeof(PeoInfoNode));
		if(!p)
		{
			printf("���ش���\n");
			return;
		}
		p->next = C->next;
		C->next = p;
		while(EOF != fscanf(pfRead,"%s %d %s %s %s\n",
			p->name,
			&(p->age),
			p->sex,
			p->tele,
			p->addr))
		{
			q = p;
			p->next = (PeoInfoNode*)malloc(sizeof(PeoInfoNode));
			if(!(p->next))
			{
				printf("���ش���\n");
				return;
			}
			p = p->next;
			++(C->age);
		}
		free(p);
		q->next = NULL;
	}
	fclose(pfRead);
	pfRead=NULL;

}

//��ʼ��ͨѶ¼����
int InitContact(Contact* pC)
{
	PeoInfoNode* p = (PeoInfoNode*)malloc(sizeof(PeoInfoNode));
	if(!p)
		return 0;
	strcpy(p->addr,"none");
	strcpy(p->name,"none");
	p->age = 0;
	strcpy(p->sex,"none");
	strcpy(p->tele,"none");
	p->next = NULL;
	*pC = p;
	load_contact(*pC);
	return 1;
}

//����ͨѶ¼���Ѻ���
int AddContact(Contact C)
{
	PeoInfoNode *p,*q;
	p = C->next;
	q = C;

	while(p)
	{
		q = p;
		p = p->next;
	}

	p = (PeoInfoNode*)malloc(sizeof(PeoInfoNode));
	if(!p)
		return 0;
	printf("���������֣�");
	scanf("%s", p->name);
	printf("�������Ա�");
	scanf("%s", p->sex);
	printf("���������䣺");
	scanf("%d", &(p->age));
	printf("������绰���룺");
	scanf("%s", p->tele);
	printf("�������ַ��");
	scanf("%s", p->addr);
	p->next = q->next;
	q->next = p;
	++(C->age);
	printf("��ӳɹ�\n");
	return 1;
}

//ɾ��ͨѶ¼���Ѻ���
void DelContact(Contact C)
{
	char DelName[MAX_NAME];
	PeoInfoNode *p,*q;
	if(C->next == NULL)
	{
		printf("��ǰû���κκ���\n");
		return;
	}
	p = C;
	q = p->next;
	printf("������Ҫɾ���ĺ��ѵ����֣�");
	scanf("%s", DelName);
	while(q)
	{
		if( !( strcmp(q->name, DelName) ) )
		{
			p->next = q->next;
			free(q);
			--(C->age);
			printf("ɾ���ɹ�\n");
			break;
		}
		p = q;
		q = q->next;
	}
	if(!q)
		printf("�ú��Ѳ�����\n");
}

//����ͨѶ¼���Ѻ���
void SearchContact(const Contact C)
{
	char SearchName[MAX_NAME] = {0};
	PeoInfoNode* p = NULL;
	if(C->next == NULL)
	{
		printf("��ǰû���κκ���\n");
		return;
	}
	printf("����Ҫ���Һ��ѵ�����\n");
	scanf("%s", SearchName);
	p = FindPeoByName(C,SearchName);
	if(!p)
	{
		printf("�ú��Ѳ�����\n");
		return;
	}
	ShowPeoInfo(p);
}

//�޸�ͨѶ¼���Ѻ���
void ModifyContact(Contact C)
{
	char SearchName[MAX_NAME] = {0};
	PeoInfoNode* p = NULL;
	if(C->next == NULL)
	{
		printf("��ǰû���κκ���\n");
		return;
	}
	printf("����Ҫ���Һ��ѵ�����\n");
	scanf("%s", SearchName);
	p = FindPeoByName(C,SearchName);
	if(!p)
	{
		printf("�ú��Ѳ�����\n");
		return;
	}
	printf("�޸�ǰ��\n");
	ShowPeoInfo(p);

	printf("�������������֣�");
	scanf("%s", p->name);
	printf("�����������Ա�");
	scanf("%s", p->sex);
	printf("�������������䣺");
	scanf("%d", &(p->age));
	printf("����������绰���룺");
	scanf("%s", p->tele);
	printf("�����������ַ��");
	scanf("%s", p->addr);

	printf("�޸����\n");
}

//��ʾͨѶ¼��¼����Ϣ����
void ShowConact(const Contact C)
{
	PeoInfoNode* p = C->next;
	if(C->next == NULL)
	{
		printf("��ǰû���κκ���\n");
		return;
	}

	while(p)
	{
		ShowPeoInfo(p);
		p = p->next;
	}
}

//����ͨѶ¼��¼����Ϣ����
void SortContact(Contact C)
{
	int input = 0;	// ��ż���������Ϣ
	if(C->next == NULL)
	{
		printf("��ǰû���κκ���\n");
		return;
	}
	do
	{
		printf("��ǰ�����б�\n");
		ShowConact(C);
		sort_contact_menu();
		scanf("%d", &input);
		switch(input)
		{
		case SORT_CANCLE:
			printf("�ɹ�ȡ������\n");
			return;
		case SORT_BY_NAME:
			PeoInfoSort(C,sort_by_name);
			return;
		case SORT_BY_AGE:
			PeoInfoSort(C,sort_by_age);
			return;
		case SORT_BY_SEX:
			PeoInfoSort(C,sort_by_sex);
			return;
		default:
			printf("�������������0-4������ѡ��\n");
			break;
		}
		system("pause");
		system("cls");
	}while(input);
	printf("�޸ĺ�����б�\n");
	ShowConact(C);
}

//�ر�ͨѶ¼����
void CloseContact(Contact C)
{
	PeoInfoNode *p,*q;
	p = C;
	q = p;

	save_contact(C);

	while(p)
	{
		q = p;
		p = p->next;
		free(q);
	}
}