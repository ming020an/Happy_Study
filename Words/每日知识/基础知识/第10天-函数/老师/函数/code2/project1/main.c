#include <stdio.h>

//int a = 10;
//int b = 100;

extern int a;
extern int b;
extern void swap(void);
int main(void)
{
	swap();
	printf("a=%d b=%d\n",a,b);

}
