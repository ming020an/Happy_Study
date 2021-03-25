#include <stdio.h>
#include <errno.h>

int main()
{
	FILE * fp1 =NULL;
	fp1 = fopen("1.txt","w+");
	if(fp1 == NULL)
	{
		perror("cuowu");
		return -1;
	}
	
	char ch[50] = {"helloworldhelloworldhelloworldhelloworldhellowo"};
	fwrite(ch,5,10,fp1);
	
	FILE *fp2 = NULL;
	fp2 = fopen("2.txt","w+");
	
	if(fp2 == NULL)
	{
		perror("cuowule");
		return -1;
	}

	fseek(fp1,0,SEEK_SET);
	char cha[50] = {0};
	
	int r = fread(cha,5,2,fp1);
	if(r == 0)
	{
		perror("fread shi bai");
		return -1;
	}
	
	int p = fwrite(cha,5,2,fp2);
	if(p == 0)
	{
		perror("fread shi bai");
		return -1;
	}
	
	fclose(fp1);
	fclose(fp2);
	
	return 0;
	
}