#include <stdio.h>
#include <errno.h>

int main()
{
	FILE *fp = fopen("stu.txt", "r");
	if (fp == NULL)
	{
		perror("fopen error:");
		return -1;
	}

	int num;
	char name[32];
	int score;
	int r;

	r = fscanf(fp, "%d%s%d", &num, name, &score);
	r = fscanf(fp, "%d%s%d", &num, name, &score);
	
	printf("num = %d name = %s score = %d r = %d\n",
		num ,name, score, r);


	fclose(fp);
	return 0;
}
