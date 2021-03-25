#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#define FIFO_NAME  "/home/gec/fifo1803"
 
int main()
{
	char buf[80];
	int fd;
	fd = mkfifo(FIFO_NAME, 0666);
	if (fd == -1)
	{
		if (errno != EEXIST) //如果出错，不是因为已经存在啦
		{
			perror("mkfifo error");
			return -1;
		}
	}
	    
    if ( fork() > 0 )
    {
        char s[] = "CS1803,Hello!";
        fd = open( FIFO_NAME, O_WRONLY );
        write( fd, s, sizeof(s) );
        //close( fd );
    }
    else
    {
        fd = open(FIFO_NAME, O_RDONLY );
        read( fd, buf, sizeof(buf) );
        printf("The message from the FIFO is:%s\n", buf );
        //close( fd );
    }
    
    return 0;
}