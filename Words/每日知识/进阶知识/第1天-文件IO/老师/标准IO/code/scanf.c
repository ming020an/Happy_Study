#include<stdio.h>

int main()
{
	int r ;
	int a ;
	char c;
	char t;
	
	//r = scanf("abcd%d %c", &a, &c);
	r = scanf("%d %c",&a,&c);
	t = getchar(); //getchar��������scanf���������\n��

	printf("a = %d c = %c r = %d\n", a,c, r);

	printf("t = %d\n", t);

	return 0;
}
