#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
/********
代码弊端：
没有考虑到映射文件它的大小，如果他是一个比较小的文件，本身系统分配给它的内存并没有映射内存大
甚至是个空文件，这时候很容易会发生错误，空文件会发生总线错误。
使用映射首先是应该考虑文件大小，我们是否要对文件进行修改，
********/
int main()
{
	int fd;
	char *p;
	
	fd = open("1.txt", O_RDWR );
	if (fd == -1)
	{
		perror("open failed");
		return -1;
	}

	p = mmap(	
			NULL, //第一个参数为映射地下，NULL表示让操作系统自行分配
			4096, //第二个参数为映射内容的长度，你可以只映射文件的一部分内容
				//但是在开辟内存时，会向上取PAGE_SIZE(4k)的整数倍
			PROT_WRITE, //第三个参数为映射区域的映射
			MAP_SHARED,//MAP_SHARED, //第四个参数为映射方式，对其他进程是否可见
			fd, //第五个参数为文件描述符，表示要映射哪个文件
			0 //第六个参数为偏移量，表示要从文件的哪个位置开始映射
		);
	if (p == MAP_FAILED)
	{
		perror("MMAP failed");
		return -1;
	}

	strcpy(p, "better future");

	//while (1);



	munmap(p, 4096);
	close(fd);
}