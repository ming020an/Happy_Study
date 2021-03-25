#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char *argv[])
{

	int fd;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("open error:");
		return -1;
	}

	char str[256] = {0};
	int r;
	r = read(fd, str, 256);

	printf("data:%s\n", str);

	close(fd);
	
	return 0;
}
