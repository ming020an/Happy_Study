#include <stdio.h>
#include <errno.h>

int main()
{
	FILE* fp1 = NULL;
	fp1 = fopen("1.txt","r+");
	if(fp1 == NULL)
	{
		perror("fopen error");
		return -1;
	}
	
	char ch[50] = {0};
	fseek(fp1, 0, SEEK_SET);
	
	fread(ch,5,2,fp1);
	int ret = ferror(fp1);
	if(ret)
	{
		perror("fread error");
		fclose(fp1);
		return -1;
	}
	fclose(fp1);
	
	FILE* fp2 = NULL;
	fp2 = fopen("2.txt","w");
	if(fp1 == NULL)
	{
		perror("fopen error");
		return -1;
	}
	
	fwrite(ch,5,2,fp2);
	ret = ferror(fp2);
	if(ret)
	{
		perror("fread error");
		fclose(fp2);
		return -1;
	}
	fclose(fp2);
		
	
	return 0;
}