#include<stdio.h>
int main()
{
	union NUM{
		int a;
		char b[4];
	}num;
	num.a=0x87654321;
	printf("0x%x\n",num.b[1]);
	printf("0x%x\n",num.b[3]);
	printf("0x%x\n",num.b[0]);
	printf("0x%x\n",num.b[2]);
	return 0;
}
