#include<stdio.h>
#include <errno.h>
int main()
{

	FILE *fp;
	fp=fopen("lx.bin","w");
	if (fp == NULL )
	{
		perror("fopen error");
		return -1;
	}
	char a[20] ="better future!";
	int ret;
	ret = fwrite(a, sizeof(a[0]), 20, fp);
	if(ret == -1)
	{
		perror("fwrite error");
		fclose(fp);
		return -1;
	}
	int i;

	for (i = 0; i < ret; i++)
	{
		printf("%c ", a[i]);
	}
	printf("\n");
	fclose(fp);
	return 0;
}
