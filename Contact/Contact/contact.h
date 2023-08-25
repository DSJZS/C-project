#ifndef __CONTACT_H__
#define __CONTACT_H__

#define MAX_PEO 1000	// ͨѶ¼�������
#define MAX_NAME 20		// ��������ַ���
#define MAX_SEX 5		// �Ա�����ַ���
#define MAX_TELE 12		// �绰����ַ���
#define MAX_ADDR 30		// ��ַ����ַ���

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct PeoInfo
{
	char name[MAX_NAME];	// ����
	int age;				// ����
	char sex[MAX_SEX];		// �Ա�
	char tele[MAX_TELE];	// �绰
	char addr[MAX_ADDR];	// ��ַ
};

struct Contact
{
	int num;	// ��ż�¼������
	struct PeoInfo data[MAX_PEO];	// ��ż�¼����Ϣ
};

//��ʼ������
void InitContact(struct Contact* ps);
//����ͨѶ¼����
void AddContact(struct Contact* ps);


#endif