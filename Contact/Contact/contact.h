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
#include<time.h>
// �����湦��
enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};
// ������湦��
enum SortOption
{
	SORT_CANCLE,
	SORT_BY_NAME,
	SORT_BY_AGE,
	SORT_BY_SEX,
	SORT_BY_TIME
};

// ��Ա��Ϣ����
struct PeoInfo
{
	char name[MAX_NAME];	// ����
	int age;				// ����
	char sex[MAX_SEX];		// �Ա�
	char tele[MAX_TELE];	// �绰
	char addr[MAX_ADDR];	// ��ַ
	struct tm* time;		// ���ʱ��
};

// ͨѶ¼����
struct Contact
{
	int num;	// ��ż�¼������
	struct PeoInfo data[MAX_PEO];	// ��ż�¼����Ϣ
};

//��ʼ��ͨѶ¼����
void InitContact(struct Contact* ps);
//����ͨѶ¼���Ѻ���
void AddContact(struct Contact* ps);
//ɾ��ͨѶ¼���Ѻ���
void DelContact(struct Contact* ps);
//����ͨѶ¼���Ѻ���
void SearchContact(const struct Contact* ps);
//�޸�ͨѶ¼���Ѻ���
void ModifyContact(struct Contact* ps);
//��ʾͨѶ¼��¼����Ϣ
void ShowConact(const struct Contact* ps);
//����ͨѶ¼��¼����Ϣ
void SortContact(struct Contact* ps);

#endif