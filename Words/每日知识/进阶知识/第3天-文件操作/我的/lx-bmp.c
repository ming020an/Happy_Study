#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main()
{
	int fd;
	char *p;
	
	fd = open("1.bmp", O_RDONLY );
	if (fd == -1)
	{
		perror("open failed");
		return -1;
	}
	char flag[2];
	lseek(fd,0,SEEK_SET);
	read(fd,&flag,2);
	if(flag[0]==0x42||flag[1]==0x4D)
	{
	int a,b,c;
	char sum[2];
	lseek(fd,2,SEEK_SET);//把光标移到最前面第二位
	read(fd,&a,4);
	printf("文件大小：%d字节\n",a);
	lseek(fd,18,SEEK_SET);
	read(fd,&b,4);
	printf("位图宽度：%d像素\n",b);
	lseek(fd,22,SEEK_SET);
	read(fd,&c,4);
	printf("位图高度：%d像素\n",c);
	lseek(fd,28,SEEK_SET);
	read(fd,&sum,2);
	printf("每像素：%d字节\n",sum[0]+(sum[1]>>8));
	close(fd);
	}
	else
	{
	printf("it isn't bmp!\n");
	close(fd);
	}
	return 0;
}