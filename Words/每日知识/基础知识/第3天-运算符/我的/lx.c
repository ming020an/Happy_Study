#include<stdio.h>
int main ()
{
	int a = 3;
	int b = 4;
	int c = a || b+a && b-a || a++;
	printf("a=%d b=%d c=%d\n",a,b,c);
	return 0;
}
