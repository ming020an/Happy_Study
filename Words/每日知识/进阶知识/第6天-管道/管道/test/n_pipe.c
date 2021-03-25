#define _GNU_SOURCE             
#include <fcntl.h>             
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

int main()
{
	//pipefd[0]用来读，pipefd[1]用来写
	int pipefd[2];//用来存放管道的两个文件描述符的
	int ret;//用来存放管道函数的返回值
	ret=pipe(pipefd);//创建管道
	if (ret == -1)
	{
		perror("pipe error");
		return -1;
	}
	//利用管道完成进程间的读写操作：父进程写信息，子进程读信息
	pid_t pid=fork();
	if (pid==-1)
	{
		perror("fork error");
		return -1;
	}
	else if (pid > 0) //父进程写信息
	{
		sleep(10);
		write(pipefd[1], "hello, son", 11);
	}
	else if (pid == 0)//子进程读信息
	{
		char buf[20];
		int r;
		r=read(pipefd[0],buf,20);
		if (r > 0)
		{
			printf("%s\n", buf);
		}
	}
}
	
