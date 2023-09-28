#define _CRT_SECURE_NO_WARNINGS 1

#include "Contact_LinkList.h"

void menu(const Contact pC)	// ��ʾ�˵�
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
	printf("��ǰ��������: %4d\n",pC->age);
	printf("��������ѡ��(0-7)\n:>");
}

int main()
{
	int input = 0;	// ��ż���������Ϣ
	Contact C;	// ����ͨѶ¼

	InitContact(&C);

	do
	{
		menu(C);
		scanf("%d", &input);
		switch(input)
		{
		case EXIT:
			CloseContact(C);
			printf("�ɹ��˳�\n");
			break;
		case ADD:
			AddContact(C);
			break;
		case DEL:
			DelContact(C);
			break;
		case SEARCH:
			SearchContact(C);
			break;
		case MODIFY:
			ModifyContact(C);
			break;
		case SHOW:
			ShowConact(C);
			break;
		case SORT:
			SortContact(C);
			break;
		default:
			printf("�������������0-7������ѡ��\n");
			break;
		}
		system("pause");
		system("cls");
	}while(input);

	return 0;
}
