#include<stdio.h>
void main()
{
	double x=1.001,y=0.001,z=1.0;
	for(int i=0;i<10;i++)
	{
		if((x-y)==z)
			printf("equal\n");
		else
			printf("not equal\n");
		x+=z;
		y+=z;
		printf("#%d:%f,%f\n",i,x,y);
	}
}
