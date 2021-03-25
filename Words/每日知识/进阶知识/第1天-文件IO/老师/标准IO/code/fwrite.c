#include <stdio.h>
#include <errno.h>

int main()
{
	#if 0
	FILE *fp;

	fp = fopen("test.bin", "w");
	if (fp == NULL)
	{
		perror("fopen error");
		return -1;
	}

	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	int ret;
	ret = fwrite(a, sizeof(a[0]), 10, fp);
	if(ret == -1)
	{
		perror("fwrite error");
		fclose(fp);
		return -1;
	}


	fclose(fp);

	#else

	FILE *fp;

	fp = fopen("test.bin", "r");
	if (fp == NULL)
	{
		perror("fopen error");
		return -1;
	}

	int a[10] ;
	int ret;
	ret = fread(a, sizeof(a[0]), 10, fp);
	if(ret == -1)
	{
		perror("fwrite error");
		fclose(fp);
		return -1;
	}
	int i;

	for (i = 0; i < ret; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	


	fclose(fp);


	#endif
}
