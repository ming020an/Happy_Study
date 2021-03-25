#include <stdio.h>
#include <errno.h>


int main(int argc, char *argv[])
{
	FILE *fp = NULL;

	fp = fopen("bucunzai.txt", "r");
	if (fp == NULL)
	{
		perror("fopen error");
	
		return -1;
	}

	int ch;

	ch = getc(fp); //fgetc(fp);
	if (ch == -1)
	{
		perror("fgetc error");

		fclose(fp);
		return -1;
	}

	printf("%c\n", ch);

	ch = fgetc(fp); //fgetc(fp);
	if (ch == -1)
	{
		perror("fgetc error");

		fclose(fp);
		return -1;
	}

	printf("%c\n", ch);

	fclose(fp); //≤ªƒ‹”√fclose("bucunzai.txt");

	return 0;
}
