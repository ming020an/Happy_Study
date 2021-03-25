#include <stdio.h>
#include <errno.h>

int main()
{
	FILE *fp = fopen("core.txt", "r");
	if (fp == NULL)
	{
		perror("fopen error:");
		return -1;
	}

	char NO[10];
	char name[32];
	int score;
	int r=3;
	printf("NO\t\t name\t\t score\t\t\n");
	while(r>1)
	{
		r = fscanf(fp,"%s%s%d",NO,name,&score);
		if(r==3)
		printf("%s\t %-8s\t %d\t%d\n",NO,name, score,r);
		
	}
	fclose(fp);
	return 0;
}