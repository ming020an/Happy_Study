#include<stdio.h>
#include<errno.h>

int main()
{
	int a;
	char p[10]={0};
	FILE *fd1=fopen("1.txt","w+");
	if(fd1==NULL)
	{
		perror("open 1 error");
		return -1;
	}
	FILE *fd2=fopen("2.txt","w+");
	if(fd2==NULL)
	{
		perror("open 2 error");
		return -1;
	}
	char * ptr="abcdefghijabcdefghijabcdefghijabcdefghijabcdefgh";
	a=fwrite(ptr,47,1,fd1);
	rewind(fd1);
	a=fread(p,5,2,fd1);
	a=fwrite(p,5,2,fd2);
	fclose(fd1);
	fclose(fd2);
	
	
	return 0;
}