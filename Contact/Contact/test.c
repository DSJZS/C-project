#define _CRT_SECURE_NO_WARNINGS 1


#include"contact.h"

void menu()	// ��ʾ�˵�
{
	printf("------------------------------\n");
	printf("* 0.�˳�ͨѶ¼				  \n");
	printf("* 1.��ź��ѵ���Ϣ			  \n");
	printf("* 2.���Ӻ�����Ϣ			  \n");
	printf("* 3.ɾ��ָ�����ֵĺ�����Ϣ    \n");
	printf("* 4.���Һ�����Ϣ  			  \n");
	printf("* 5.�޸ĺ�����Ϣ			  \n");
	printf("* 6.��ʾ������Ϣ			  \n");
	printf("* 7.���������Ϣ			  \n");
	printf("------------------------------\n");
	printf("��������ѡ��(0-7)\n:>");
}

int main()
{
	int input = 0;	// ��ż���������Ϣ
	struct Contact con;	// ����ͨѶ¼
	
	InitContact(&con);

	do
	{
		menu();
		scanf("%d", &input);
		switch(input)
		{
		case 0:
			printf("�ɹ��˳�\n");
			break;
		case 1:
			AddContact(&con);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			ShowConact(&con);
			break;
		case 7:
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