#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
#include<errno.h>
#include <unistd.h>
int main()
{
	int fd1,fd2;
	fd1=open("1.txt", O_RDONLY, 0444);
	if (fd1 == -1)
	{
		perror("open error");
		return -1;
	}
	fd2=open("2.txt", O_WRONLY, 0222);
	char longth[20]={"\0"};
	 lseek(fd1,0,SEEK_SET);//把光标移到最前面
	int a;
	a =read(fd1,longth,20);
	if (a== -1)
	{
		perror("read error");
		return -1;
	}
	printf("%s\n",longth);
	int flag;
	 lseek(fd2,0,SEEK_SET);
	flag=write(fd2,longth,20);
	if (flag== -1)
	{
		perror("write error");
		return -1;
	}
	close(fd1);
	close(fd2);
	return 0;
}
