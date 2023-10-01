#define _CRT_SECURE_NO_WARNINGS 1

#include "SqString.h"

int main()
{
	SqString S1;
	SqString S2;
	int i = 0;
	S1.ch = "abcdefhfjhgtefgeyjhkloiu";
	S1.length = 24;
	S2.ch = "efg";
	S2.length = 3;

	i = index_KMP(&S1,&S2,0);

	return 0;
}