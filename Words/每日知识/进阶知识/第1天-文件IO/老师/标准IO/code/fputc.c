#include <stdio.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	FILE *fp = NULL;

	fp = fopen(argv[1], "a");
	if (fp == NULL)
	{
		perror("fopen error:");
		return -1;
	}


	fputc('B', fp); //putc('B', fp);
	

	fclose(fp);
	
}
