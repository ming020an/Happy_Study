#include<stdio.h>
int main()
{
	FILE* fp1;
	FILE* fp2;
	fp1=fopen("./1.txt","r");
	if(NULL==fp1)
	{
		perror("fp1 error");
		return -1;
	}
	int r_ret;
	int w_ret;
	char buf[50]={0};
	
	//读取fp1
	do
	{
		//fseek(fp1,0,SEEK_SET);
		r_ret=fread(buf,5,10,fp1);
		if(r_ret)
		{
			printf("r_ret=%d\n",r_ret);
			printf("%s\n",buf);
		}
	}while(!feof(fp1));
	fp2=fopen("./2.txt","w");
	if(NULL==fp2)
	{
		perror("fp2 error");
		return -1;
	}
	//写入fp2

	
	w_ret=fwrite(buf,5,2,fp2);
	if(w_ret)
	{
		printf("w_ret=%d\n",w_ret);
		;
	}
	
	fclose(fp1);
	fclose(fp2);
}