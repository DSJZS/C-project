#include "error.h"

int ConfirmError(Status error)
{
	switch(error)
	{
	case OK:
		return 0;
	case OVERFLOW:
		printf("�ڴ�ռ�����\n");
		break;
	case NOFOUND:
		printf("δ�ҵ��ļ�\n");
		break;
	case LONGNAME:
		printf("�ļ����������뽫������\n");
		break;
	case WRONGPWD:
		printf("���������\n");
		break;
	case WRONGMARK:
		printf("������ļ���ǣ��ļ�ѹ����ʽ��ƥ�䣬���ܲ��Ǹø�ʽѹ���ļ�\n");
		break;
	case UNKNOW:
	default:
		perror("δ֪�����ɱ������жϵó���");
		break;
	}
	return 1;
}