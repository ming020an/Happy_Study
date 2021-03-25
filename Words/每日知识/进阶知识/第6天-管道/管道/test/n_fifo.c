#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#define FIFO_NAME  "/home/gec/fifo1803"
main()
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
	    
    if ( fork() > 0 )//父进程，写信息
    {
        char s[] = "CS1803,rang wo men qu chifan!";
        fd = open( FIFO_NAME, O_WRONLY );//打开文件
        write( fd, s, sizeof(s) );//将字符串写入管道文件
        //close( fd );
    }
    else //子进程，读信息
    {
        fd = open( FIFO_NAME, O_RDONLY );
        read( fd, buf, sizeof(buf) );//将字符串从管道文件读到buf
        printf("The message from the FIFO is:%s\n", buf );
        //close( fd );
    }
    
    return 0;
	
}