#include<stdio.h>
#include<errno.h>
#include<string.h>

int main()
{
	FILE *fp1 = fopen("1.txt","r");
	if(fp1 == NULL)
	{
		perror("fopen fp1 error");
		return -1;
	}
	
	FILE *fp2 = fopen("2.txt","w");
	if(fp2 == NULL)
	{
		perror("fopen fp2 error");
		return -1;
	}
	
	char buf[50];
	int r_ret ;
	int w_ret;
	while(!feof(fp1))
	{
		r_ret = fread(buf,5,2,fp1);
		if(r_ret == -1)
		{
			perror("fread fp1 error");
			return -1;
		}
		
		w_ret = fwrite(buf,5,2,fp2);
		if(w_ret == -1)
		{
			perror("fwrite fp2 error");
			return -1;
		}
		
		bzero(buf, 10);//清空数组

	}
	
	fclose(fp1);
	fclose(fp2);
	
	return 0;
}