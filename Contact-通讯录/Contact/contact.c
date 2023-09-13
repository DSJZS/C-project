#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"
// 查找个人信息位置返回其下标
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
// 用于SortContact函数排序个人信息
static void sort_contact_menu()	// 显示菜单
{
	printf("------------------------------\n");
	printf("* 0.取消排序				  \n");
	printf("* 1.按名字排序				  \n");
	printf("* 2.按年龄排序				  \n");
	printf("* 3.按性别排序	  			  \n");
	printf("------------------------------\n");
	printf("输入数字选择(0-3)\n:>");
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
// 检查通讯录是否容量已满
static int check_capacity(struct Contact* ps)
{
	if(ps->num == ps->capacity)
		return 1;
	else
		return 0;
}
// 增加容量
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
// 保存通讯录
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
// 加载通讯录
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
// 初始化
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
// 增加
void AddContact(struct Contact* ps)
{
	if(ps->num == MAX_PEO)
		printf("通讯录已满，无法存放新的好友的信息\n");
	else
	{
		if(check_capacity(ps))
		{
			increase_capacity(ps);
		}
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
		printf("输入完毕\n");
	}
}
// 删除
void DelContact(struct Contact* ps)
{
	char DelName[MAX_NAME] = {0};
	int pos = 0;
	if(ps->num == 0)
	{
		printf("当前通讯录为空，请添加好友信息\n");
		return;
	}
	printf("输入删除好友名字\n:>");
	scanf("%s", DelName);
	pos = find_by_name(ps,DelName);
	if(pos == -1)
		printf("删除失败，原因：查无此人\n");
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
			printf("删除成功\n");
		}
	}

			
}
// 查找
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
		printf("%20s\t%4s\t%5s\t%12s\t%20s\n","名字","年龄","性别","电话","地址");
		printf("%20s\t%4d\t%5s\t%12s\t%20s\n",
			ps->data[pos].name,
			ps->data[pos].age,
			ps->data[pos].sex,
			ps->data[pos].tele,
			ps->data[pos].addr);
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
		printf("%20s\t%4s\t%5s\t%12s\t%20s\n","名字","年龄","性别","电话","地址");
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
// 排序
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
		sort_contact_menu();
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
		default:
			printf("输入错误，请输入0-4的数字选项\n");
			break;
		}
		system("pause");
		system("cls");
	}while(input);
}
// 关闭
void CloseContact(struct Contact* ps)
{
	save_contact(ps);
	

	free(ps->data);
	ps->data=NULL;
}


