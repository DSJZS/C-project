#ifndef __CONTACT_LINKLIST_H__
#define __CONTACT_LINKLIST_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 人名最大字符数
#define MAX_NAME 20		
// 性别最大字符数
#define MAX_SEX 5		
// 电话最大字符数
#define MAX_TELE 12		
// 地址最大字符数
#define MAX_ADDR 30	

// 主界面功能
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
// 排序界面功能
enum SortOption
{
	SORT_CANCLE,
	SORT_BY_NAME,
	SORT_BY_AGE,
	SORT_BY_SEX,
};

typedef struct PeoInfoNode{
	char name[MAX_NAME];	// 名字 - 数据域
	int age;				// 年龄(头结点此处记录人员数量) - 数据域	
	char sex[MAX_SEX];		// 性别 - 数据域
	char tele[MAX_TELE];	// 电话 - 数据域
	char addr[MAX_ADDR];	// 地址 - 数据域
	struct PeoInfoNode* next;	// 指向下一个信息结构体的指针 - 指针域
}PeoInfoNode, *Contact;


//初始化通讯录函数
int InitContact(Contact* pC);
//增加通讯录好友函数
int AddContact(Contact C);
//删除通讯录好友函数
void DelContact(Contact C);
//查找通讯录好友函数
void SearchContact(const Contact C);
//修改通讯录好友函数
void ModifyContact(Contact C);
//显示通讯录记录人信息函数
void ShowConact(const Contact C);
//排序通讯录记录人信息函数
void SortContact(Contact C);
//关闭通讯录函数
void CloseContact(Contact C);

#endif __CONTACT_LINKLIST_H__