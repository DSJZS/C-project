#define _CRT_SECURE_NO_WARNINGS 1

#include "memsize.h"

long get_file_size(FILE *stream)
{
	long file_size = -1;
	long cur_offset = ftell(stream);	// ��ȡ��ǰƫ��λ��
	if (cur_offset == -1) {
		printf("ftell failed :%s\n", strerror(errno));
		return -1;
	}
	if (fseek(stream, 0, SEEK_END) != 0) {	// �ƶ��ļ�ָ�뵽�ļ�ĩβ
		printf("fseek failed: %s\n", strerror(errno));
		return -1;
	}
	file_size = ftell(stream);	// ��ȡ��ʱƫ��ֵ�����ļ���С
	if (file_size == -1) {
		printf("ftell failed :%s\n", strerror(errno));
	}
	if (fseek(stream, cur_offset, SEEK_SET) != 0) {	// ���ļ�ָ��ָ���ʼλ��
		printf("fseek failed: %s\n", strerror(errno));
		return -1;
	}
	return file_size;
}
