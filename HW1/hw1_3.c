#include<stdio.h>
int main()
{
	unsigned int a=1;
	unsigned short b=1;
	char c=-1;
	int d;

	d=(a>c)?1:0;
	printf("unsigned int is %d\n",d);
	d=(b>c)?1:0;
	printf("unsigned short is %d\n",d);
	return 0;
}
