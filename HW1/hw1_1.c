#include<stdio.h>
#include<stdlib.h>
#define OFFSET(type,field) ((size_t)&(((type*)0)->field))
//#pragma pack(2)
#pragma pack(32)
struct test1{
	char x1[15];
	short x2[3];
	int x3;
	long long x4;
};
struct test2{
	char x1[15];
	short x2[3];
	int x3;
	long long x4;
}__attribute__((aligned(16)));

int main()
{
	printf("struct size is:%d\n",sizeof(struct test1));
	printf("allocate x1 on address:%d\n",OFFSET(struct test1,x1));
	printf("allocate x2 on address:%d\n",OFFSET(struct test1,x2));
	printf("allocate x3 on address:%d\n",OFFSET(struct test1,x3));
	printf("allocate x4 on address:%d\n",OFFSET(struct test1,x4));

	printf("struct size is %d\n",sizeof(struct test2));
	printf("allocate x1 on address:%d\n",OFFSET(struct test2,x1));
	printf("allocate x2 on address:%d\n",OFFSET(struct test2,x2));
	printf("allocate x3 on address:%d\n",OFFSET(struct test2,x3));
	printf("allocate x4 on address:%d\n",OFFSET(struct test2,x4));
	return 0;
}
