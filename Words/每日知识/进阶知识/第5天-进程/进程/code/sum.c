#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[],char *envp[])
{
	int a,b;
	a = atoi(argv[1]);
	b = atoi(argv[2]);
	printf("ll%d\n",a + b );
	printf("kkk=%s\n",envp[1]);
	exit(88);
}