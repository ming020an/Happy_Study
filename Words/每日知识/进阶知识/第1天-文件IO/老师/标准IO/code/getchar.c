#include <stdio.h>
#include <errno.h>

int main()
{
	int ch;

	//ch = getchar(); 
	ch = fgetc(stdin);

	printf("%c\n", ch);


	return -1;
}
