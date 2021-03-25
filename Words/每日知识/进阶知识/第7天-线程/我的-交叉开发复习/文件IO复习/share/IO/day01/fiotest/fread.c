#include<stdio.h>
#include <string.h>

int main(void)
{
	FILE *fp1 = fopen("1.txt","r");
	if(fp1 == NULL)
	{
		perror("fopen 1.txt error");
		return -1;
	}

	FILE *fp2 = fopen("2.txt","w");
	if(fp2 == NULL)
	{
		perror("fopen 2.txt error");
		return -1;
	}	
	
	char buf[128] = {0};
	//10  10 10 10 7
	while(1)
	{
		bzero(buf,128);
		int r = fread(buf,5,2,fp1);
		printf("r = %d\n",r);
		if(r == 2)
		{
			fwrite(buf,5,2,fp2);
		}	
		
		else if(r != 2 && feof(fp1) == 1)
		{
			fwrite(buf,7,1,fp2);
			break;
		}		
		
		else if(r != 2 && ferror(fp1) == 1)
		{
			perror("fread 1.txt error");
			return -1;
		}		
	}
	
	fclose(fp1);
	fclose(fp2);
	return 0;
	
}