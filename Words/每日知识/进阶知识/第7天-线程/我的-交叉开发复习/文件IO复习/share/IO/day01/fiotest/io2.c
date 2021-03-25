#include<stdio.h>
#include<errno.h>
#include<string.h>

int main()
{
	FILE *fp1,*fp2;
	int r_ret,w_ret,r=0;
	char buf[256]={0};
	char ch[10]="          ";
	fp1=fopen("1.txt","r");
	if(fp1==NULL)
	{
		perror("fopen error");
		return -1;
	}
	
	fp2=fopen("2.txt","w");
	if(fp2==NULL)
	{
		perror("fopen error");
		return -1;
	}
	
	while(feof(fp1)==0)
	{
		r_ret=fread(buf,5,2,fp1);
		if(r_ret==-1)
		{
			perror("fread error");
			return -1;
		}

		w_ret=fwrite(buf,5,2,fp2);
		if(w_ret==-1)
		{
			perror("fwrite error");
			return -1;
		}
		//strncpy(buf,ch,10);
		//bzero(buf,10);
		//memset(buf,1,10);
	}
	
	fclose(fp1);
	fclose(fp2);
	return 0;
}