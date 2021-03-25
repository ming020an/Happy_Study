#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	int fd1;
	int fd2;
	int w_ret;
	int r_ret;
	char buf[15] = {0};

	//1、打开1.txt 
	fd1 = open("./1.txt", O_RDWR);
	if (fd1 == -1)
	{
		perror("open ./1.txt failed!");
		return -1;
	}else
	{
		printf("fd1 = %d\n",fd1);
	}

	//2、写入1.txt 
	w_ret = write(fd1,"hello world",12);
	if (w_ret == -1)
	{
		perror("write ./1.txt failed!");
		return -1;
	}else{
		printf("w_ret = %d\n",w_ret);
		printf("write ./1.txt success!\n");
	}



	//3、打开2.txt 
	fd2 = open("./2.txt", O_RDWR);
	if (fd2 == -1)
	{
		perror("open ./2.txt failed!");
		return -1;
	}else
	{
		printf("fd2 = %d\n",fd2);
	}

	//4、将光标设置在文件最开始
	lseek(fd1,0,SEEK_SET);

	//5、读取1.txt 
	r_ret = read(fd1,buf,w_ret);
	if (r_ret == -1)
	{
		perror("read ./1.txt failed!");
		return -1;
	}else{
		printf("r_ret = %d\n",r_ret);
		printf("read ./2.txt success!\n");
	}

	//2、写入2.txt 
	w_ret = write(fd2,buf,r_ret);
	if (w_ret == -1)
	{
		perror("write ./2.txt failed!");
		return -1;
	}else{
		printf("w_ret = %d\n",w_ret);
		printf("write ./2.txt success!");
	}
	//6、关闭2.txt
	close(fd2);
	close(fd1);
	return 0;
}