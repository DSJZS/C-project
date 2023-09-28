#ifndef __CONTACT_LINKLIST_H__
#define __CONTACT_LINKLIST_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// ��������ַ���
#define MAX_NAME 20		
// �Ա�����ַ���
#define MAX_SEX 5		
// �绰����ַ���
#define MAX_TELE 12		
// ��ַ����ַ���
#define MAX_ADDR 30	

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
};

typedef struct PeoInfoNode{
	char name[MAX_NAME];	// ���� - ������
	int age;				// ����(ͷ���˴���¼��Ա����) - ������	
	char sex[MAX_SEX];		// �Ա� - ������
	char tele[MAX_TELE];	// �绰 - ������
	char addr[MAX_ADDR];	// ��ַ - ������
	struct PeoInfoNode* next;	// ָ����һ����Ϣ�ṹ���ָ�� - ָ����
}PeoInfoNode, *Contact;


//��ʼ��ͨѶ¼����
int InitContact(Contact* pC);
//����ͨѶ¼���Ѻ���
int AddContact(Contact C);
//ɾ��ͨѶ¼���Ѻ���
void DelContact(Contact C);
//����ͨѶ¼���Ѻ���
void SearchContact(const Contact C);
//�޸�ͨѶ¼���Ѻ���
void ModifyContact(Contact C);
//��ʾͨѶ¼��¼����Ϣ����
void ShowConact(const Contact C);
//����ͨѶ¼��¼����Ϣ����
void SortContact(Contact C);
//�ر�ͨѶ¼����
void CloseContact(Contact C);

#endif __CONTACT_LINKLIST_H__