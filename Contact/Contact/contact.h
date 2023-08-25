#ifndef __CONTACT_H__
#define __CONTACT_H__

#define MAX_PEO 1000	// 通讯录最大人数
#define MAX_NAME 20		// 人名最大字符数
#define MAX_SEX 5		// 性别最大字符数
#define MAX_TELE 12		// 电话最大字符数
#define MAX_ADDR 30		// 地址最大字符数

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct PeoInfo
{
	char name[MAX_NAME];	// 名字
	int age;				// 年龄
	char sex[MAX_SEX];		// 性别
	char tele[MAX_TELE];	// 电话
	char addr[MAX_ADDR];	// 地址
};

struct Contact
{
	int num;	// 存放记录的人数
	struct PeoInfo data[MAX_PEO];	// 存放记录人信息
};

//初始化函数
void InitContact(struct Contact* ps);
//增加通讯录函数
void AddContact(struct Contact* ps);


#endif