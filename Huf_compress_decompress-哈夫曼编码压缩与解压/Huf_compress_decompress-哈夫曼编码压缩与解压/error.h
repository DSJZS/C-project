#ifndef __ERROR_H__
#define __ERROR_H__

/*	���ִ����ʶ��������ʾ���ִ���	*/

// �ú�������������
//	#define _DEBUG_


#include <stdio.h>	/*	func printf	*/

typedef enum Status{
	OK,
	OVERFLOW,
	UNKNOW,
	NOFOUND,
	LONGNAME,
	WRONGPWD,
	WRONGMARK
}Status;


/*ȷ�ϴ�������д����ӡ������Ϣ���ҷ��� 1�����򷵻� 0	
�βΣ�
error - ������
����ֵ��
����д��󣬷���1
û�з��� 0
*/
int ConfirmError(Status error);

#endif;