#ifndef __LINKSTRING_H__
#define __LINKSTRING_H__

/*	������Ϊ������	*/
/*	����c�����Դ�����ַ������������ṹ��δд�꣬��ΪĿǰû��Ҫ	*/

typedef struct Chunk{
	char* ch;	// ������
	struct Chunk* next;	// ָ����
}Chunk;	// �ַ�����

typedef struct LinkString{
	Chunk *head,*tail;	// ͷָ�룬βָ��
	int strlen;	// ���ĳ���
	int chunkSize;	// ÿ����Ĵ�С
}LinkString;

#endif