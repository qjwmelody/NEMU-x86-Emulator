#include<stdio.h>
int main()
{
	int a=(-1<1)?1:0;
	int b=(-1<1u)?1:0;
	printf("the result of -1<1 is %d\n",a);
	printf("the result of -1<1u is %d\n",b);
	return 0;
}
