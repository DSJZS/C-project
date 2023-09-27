#define _CRT_SECURE_NO_WARNINGS 1

#include "Contact_LinkList.h"

// 显示一个好友的信息
static void ShowPeoInfo(const PeoInfoNode* PeoInfo)
{
			printf("%20s\t%4s\t%5s\t%12s\t%20s\n","名字","年龄","性别","电话","地址");
			printf("%20s\t%4d\t%5s\t%12s\t%20s\n",
				PeoInfo->name,
				PeoInfo->age,
				PeoInfo->sex,
				PeoInfo->tele,
				PeoInfo->addr);
}

// 根据名字查找一个好友的位置
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

// 排序函数专用显示菜单
static void sort_contact_menu()	
{
	printf("------------------------------\n");
	printf("* 0.取消排序				  \n");
	printf("* 1.按名字排序				  \n");
	printf("* 2.按年龄排序				  \n");
	printf("* 3.按性别排序	  			  \n");
	printf("------------------------------\n");
	printf("输入数字选择(0-3)\n:>");
}

// 排序函数专用通用排序
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

// 排序函数专用比较函数
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

// 保存通讯录到本地
static void save_contact(Contact C)
{
	FILE* pfWrite = fopen("PeoInfo.txt","w");
	if(!pfWrite)
	{
		printf("保存失败\n");
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

// 从本地加载通讯录
static void load_contact(Contact C)
{
	FILE* pfRead = fopen("PeoInfo.txt","r");
	PeoInfoNode *p,*q;
	if(pfRead == NULL)
	{
		printf("欢迎你，新用户\n");
		return;
	}
	else
	{
		p = (PeoInfoNode*)malloc(sizeof(PeoInfoNode));
		if(!p)
		{
			printf("加载错误\n");
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
				printf("加载错误\n");
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

//初始化通讯录函数
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

//增加通讯录好友函数
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
	printf("请输入名字：");
	scanf("%s", p->name);
	printf("请输入性别：");
	scanf("%s", p->sex);
	printf("请输入年龄：");
	scanf("%d", &(p->age));
	printf("请输入电话号码：");
	scanf("%s", p->tele);
	printf("请输入地址：");
	scanf("%s", p->addr);
	p->next = q->next;
	q->next = p;
	++(C->age);
	printf("添加成功\n");
	return 1;
}

//删除通讯录好友函数
void DelContact(Contact C)
{
	char DelName[MAX_NAME];
	PeoInfoNode *p,*q;
	if(C->next == NULL)
	{
		printf("当前没有任何好友\n");
		return;
	}
	p = C;
	q = p->next;
	printf("请输入要删除的好友的名字：");
	scanf("%s", DelName);
	while(q)
	{
		if( !( strcmp(q->name, DelName) ) )
		{
			p->next = q->next;
			free(q);
			--(C->age);
			printf("删除成功\n");
			break;
		}
		p = q;
		q = q->next;
	}
	if(!q)
		printf("该好友不存在\n");
}

//查找通讯录好友函数
void SearchContact(const Contact C)
{
	char SearchName[MAX_NAME] = {0};
	PeoInfoNode* p = NULL;
	if(C->next == NULL)
	{
		printf("当前没有任何好友\n");
		return;
	}
	printf("输入要查找好友的名字\n");
	scanf("%s", SearchName);
	p = FindPeoByName(C,SearchName);
	if(!p)
	{
		printf("该好友不存在\n");
		return;
	}
	ShowPeoInfo(p);
}

//修改通讯录好友函数
void ModifyContact(Contact C)
{
	char SearchName[MAX_NAME] = {0};
	PeoInfoNode* p = NULL;
	if(C->next == NULL)
	{
		printf("当前没有任何好友\n");
		return;
	}
	printf("输入要查找好友的名字\n");
	scanf("%s", SearchName);
	p = FindPeoByName(C,SearchName);
	if(!p)
	{
		printf("该好友不存在\n");
		return;
	}
	printf("修改前：\n");
	ShowPeoInfo(p);

	printf("请重新输入名字：");
	scanf("%s", p->name);
	printf("请重新输入性别：");
	scanf("%s", p->sex);
	printf("请重新输入年龄：");
	scanf("%d", &(p->age));
	printf("请重新输入电话号码：");
	scanf("%s", p->tele);
	printf("请重新输入地址：");
	scanf("%s", p->addr);

	printf("修改完成\n");
}

//显示通讯录记录人信息函数
void ShowConact(const Contact C)
{
	PeoInfoNode* p = C->next;
	if(C->next == NULL)
	{
		printf("当前没有任何好友\n");
		return;
	}

	while(p)
	{
		ShowPeoInfo(p);
		p = p->next;
	}
}

//排序通讯录记录人信息函数
void SortContact(Contact C)
{
	int input = 0;	// 存放键盘输入信息
	if(C->next == NULL)
	{
		printf("当前没有任何好友\n");
		return;
	}
	do
	{
		printf("当前好友列表：\n");
		ShowConact(C);
		sort_contact_menu();
		scanf("%d", &input);
		switch(input)
		{
		case SORT_CANCLE:
			printf("成功取消排序\n");
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
			printf("输入错误，请输入0-4的数字选项\n");
			break;
		}
		system("pause");
		system("cls");
	}while(input);
	printf("修改后好友列表：\n");
	ShowConact(C);
}

//关闭通讯录函数
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