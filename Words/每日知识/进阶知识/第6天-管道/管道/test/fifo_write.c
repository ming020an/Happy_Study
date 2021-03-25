
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
		if (errno != EEXIST) //�������������Ϊ�Ѿ�������
		{
			perror("mkfifo error");
			return -1;
		}
	}

	int fd;

	fd = open(FIFO_NAME, O_WRONLY);//�������ȴ�д�˴�
	//fd = open(FIFO_NAME, O_WRONLY | O_NONBLOCK);//�Է������ķ�ʽȥд�����
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
