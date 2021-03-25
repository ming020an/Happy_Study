#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char *argv[])
{
	int r;
	int  pipefd[2]; //用来存放管道的读、写文件描述符的
	int pid;
	
	r = pipe(pipefd);  //先于fork创建管道
	if (r == -1)
	{
		perror("pipe error:");
		return -1;
	}

	int st;
	pid = fork();
	if (pid > 0)  //父进程
	{
		r = write(pipefd[1], "hello", 5);
		wait(&st);
	} 
	else if (pid == 0) //子进程
	{
		char str[256] = {0};
		r = read(pipefd[0], str, 256);
		if (r > 0)
		{
			printf("chlid data: %s\n",str);
		}
	}
	
	close(pipefd[0]);
	close(pipefd[1]);
	return 0;
}
//chlid data: hello
