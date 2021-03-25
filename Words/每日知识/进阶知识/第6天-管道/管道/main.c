#include <fcntl.h>         
#include <unistd.h>
#include<stdio.h>

int main()
{
	int pipe(pipefd[2]);
	
	pid_t re;
	
	re = fork();
	if(re > 0)
	{
		write(pipefd[1],"hello world",12);
		
	}
	else if(re==0)
	{
		buf[50];
		read(pipefd[0],buf,20);
	}
	printf("buf = %s\n",buf);
}