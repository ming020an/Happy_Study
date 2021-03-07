#include<stdio.h>
extern int a,b;
extern void my_ex(void);
int main(void)
{
	scanf("%d%d",&a,&b);
	my_ex();
	printf("%d\t%d",a,b);
	return 0;
}