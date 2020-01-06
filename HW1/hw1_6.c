#include<stdio.h>
float u2f(unsigned u)
{
	return *(float *)&u;
}
float fpower2(int x)
{
	unsigned exp,frac,u;
	if(x<-149)
	{
		//the value is too small, return 0.0
		exp=0;
		frac=0;
	}
	else if(x<-126)
	{
		//return denormalized number
		exp=0;
		frac=1<<(x+149);
	}
	else if(x<128)
	{
		//return normalized number
		exp=x+127;
		frac=0;
	}
	else
	{
		//the value is too big, return infinite
		exp=255;
		frac=0;
	}
	u=exp<<23|frac;
	printf("2^%d=%fD=0x%x\n",x,u2f(u),u);
	return u2f(u);
}
int main()
{
	int x;
	printf("Please input an integer: \n");
	scanf("%d",&x);
	fpower2(x);
	return 0;
}
