#include <unistd.h>
#include <stdio.h>
#include <errno.h>

int main()
{
	int pfd[2]; //用来存放管道的两个文件描述符的
	int r;

	r = pipe(pfd);
	if (r == -1)
	{
		perror("pipe error");
		return -1;
	}

	pid_t pid = fork();

	if (pid > 0)
	{
		write(pfd[1], "hello, son", 11);
	}
	else if (pid == 0)
	{
		char buf[32];
		r = read(pfd[0], buf, 32);
		if (r > 0)
		{
			printf("%s\n", buf);
		}
	}
	
}
//hello, son

