#include <stdio.h>

struct test4
{
	int y,m,d; //年月日
};

struct test2
{
	int c; //0x10
	char a;//0x14
	char b;//0x15
	struct test4 birth;//sizeof(birth) == 12
};//sizeof(struct test2) == 20
//c(4)ab__birth(12)

int main(void)
{
	struct test2 a;
	printf("%d %d %d\n",sizeof(a),
			sizeof(struct test2),
			sizeof(struct test4));
}