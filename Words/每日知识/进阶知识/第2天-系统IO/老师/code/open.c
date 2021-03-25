#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>

int main()
{
	int fd;

	fd = open("/home/gec/sb.txt", O_RDWR | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("open error");
		return -1;
	}



	close(fd);
}
			
