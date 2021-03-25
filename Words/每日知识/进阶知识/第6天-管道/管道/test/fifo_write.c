
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#define FIFO_NAME  "/home/gec/fifo1803"
int main()
{
	int r;

	r = mkfifo(FIFO_NAME, 0664);
	if (r == -1)
	{
		if (errno != EEXIST) //如果出错，不是因为已经存在啦
		{
			perror("mkfifo error");
			return -1;
		}
	}

	int fd;

	fd = open(FIFO_NAME, O_WRONLY);//会阻塞等待写端打开
	//fd = open(FIFO_NAME, O_WRONLY | O_NONBLOCK);//以非阻塞的方式去写会出错
	if (fd == -1)
	{
		perror("open fifo error");
		return -1;
	}

	printf("successfully opened wr\n");


	char buf[32];
	fgets(buf, 32, stdin);

	write(fd, buf, strlen(buf) + 1);

	close(fd);

}
