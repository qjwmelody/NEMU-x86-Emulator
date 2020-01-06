#include<stdio.h>
int main()
{
	int x=-1;
	unsigned u=2147483648;
	printf("x=%u=%d\n",x,x);
	printf("u=%u=%d\n",u,u);

	if(-2147483648<2147483647)
	{

		printf("-2147483648<2147483647 is true\n");
	}
	else 
	{

		printf("-2147483648<2147483647 is false\n");
	}

	if(-2147483648-1<2147483647)
	{

		printf("-2147483648-1<2147483647\n");
	}
	else if(-2147483648-1==2147483647)
	{

		printf("-2147483648-1==2147483647\n");
	}
	else 
	{

		printf("-2147483648-1>2147483647\n");
	}
	return 0;
}
