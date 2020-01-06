#include<stdio.h>
int main()
{
	int a=2147483648;
	int b=-2147483648;
	int c=2147483649;
	unsigned short d=65539;
	short e=-32790;
	printf("a=%x\n",a);
	printf("b=%x\n",b);
	printf("c=%x\n",c);
	printf("d=%x\n",d);
	printf("e=%x\n",e);
	return 0;
}
