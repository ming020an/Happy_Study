
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

int main()
{
	printf("hello");

	sleep(10);
	fflush(NULL);

	while(1);
}
