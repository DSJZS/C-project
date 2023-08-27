#define _CRT_SECURE_NO_WARNINGS 1


#include"contact.h"

void menu(const struct Contact* ps)	// ��ʾ�˵�
{
	printf("------------------------------\n");
	printf("* 0.�˳�ͨѶ¼				  \n");
	printf("* 1.���Ӻ�����Ϣ			  \n");
	printf("* 2.ɾ��ָ�����ֵĺ�����Ϣ    \n");
	printf("* 3.���Һ�����Ϣ  			  \n");
	printf("* 4.�޸ĺ�����Ϣ			  \n");
	printf("* 5.��ʾ������Ϣ			  \n");
	printf("* 6.���������Ϣ			  \n");
	printf("------------------------------\n");
	printf("��ǰ��������(%4d/%4d)\n",ps->num,MAX_PEO);
	// printf("test:%d\n",ps->maxNum);
	printf("��������ѡ��(0-7)\n:>");
}

int main()
{
	int input = 0;	// ��ż���������Ϣ
	struct Contact con;	// ����ͨѶ¼
	
	InitContact(&con);

	do
	{
		menu(&con);
		scanf("%d", &input);
		switch(input)
		{
		case EXIT:
			printf("�ɹ��˳�\n");
			break;
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowConact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		default:
			printf("�������������0-7������ѡ��\n");
			break;
		}
		system("pause");
		system("cls");
	}while(input);
	free(con.data);
	con.data = NULL;
	return 0;
}