#include<stdio.h>
#include<errno.h>
int main ()
{
	FILE *fp1=NULL;
	FILE *fp2=NULL;
	fp1=fopen("1.txt","r");
	if(fp1==NULL)
	{
		perror("fopen error!");
		return -1;
	}
	fp2=fopen("2.txt","w");
	char longth[20]={"\0"};
	fseek(fp1,0,SEEK_SET);//把光标移到最前面
	int a;
	a=fread(longth,sizeof(longth[0]),20,fp1);//返回值是整型，必须用一个整型的变量去接收，读操作直接运行了
	printf("%s\n",longth);
	if(a==0)
	{
		perror("fread error!");
		fclose(fp1);
		return -1;
	}
	int flag;
	fseek(fp2,0,SEEK_SET);
	flag=fwrite(longth,sizeof(longth[0]),20,fp2);
	if(flag==-1)
	{
		perror("fwrite error!");
		fclose(fp2);
		return -1;
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}