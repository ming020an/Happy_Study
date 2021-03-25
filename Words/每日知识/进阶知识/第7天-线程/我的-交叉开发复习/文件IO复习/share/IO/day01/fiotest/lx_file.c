#include<stdio.h>
#include<errno.h>
int main()
{
	FILE * fp1 = NULL;
	FILE * fp2 = NULL;
	
	fp1 = fopen("1.txt","w+");
	if(fp1==NULL)
	{
		perror("open error");
		return -1;
	}

	fp2 = fopen("2.txt","w");
	if(fp2==NULL)
	{
		perror("open error");
		return -1;
	}
	char *p = "abcdefghijabcdefghijabcdefghijabcdefghijabcdefghi";
	char buf[50] = {};
	
	int flag;
	flag = fwrite(p,47,1,fp1);
	if(flag==-1)
	{
		perror("write error");
		fclose(fp1);
		return -1;
	}
	
	fseek(fp1,0,SEEK_SET);
	fread(buf,5,2,fp1);
	if(flag==-1)
	{
		perror("read error");
		fclose(fp1);
		return -1;
	}
	
	fwrite(buf,5,2,fp2);
	if(flag==-1)
	{
		perror("write error");
		fclose(fp1);
		return -1;
	}
	fclose(fp1);
	fclose(fp2);
	
	return 0;
}