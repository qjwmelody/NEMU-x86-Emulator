#include<stdio.h>
int main()
{
	int a=(-2147483648<2147483647)?1:0;
	printf("the result of -2147483648<2147483647 is:%d\n",a);

	int i=-2147483648;
	int b=(i<2147483647)?1:0;
	printf("the result of i<2147483647 is:%d\n",b);

	int c=(-2147483647-1<2147483647)?1:0;
	printf("the result of -2147483647-1<2147483647 is:%d\n",c);
	return 0;
}
