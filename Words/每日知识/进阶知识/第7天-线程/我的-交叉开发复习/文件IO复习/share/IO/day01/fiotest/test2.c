#include <stdio.h>




int main()
{
	FILE *fd1;
	FILE *fd2;
	size_t w_ret,r_ret;
	char ptr[50];
	
	//1.打开1.txt
	fd1 = fopen("./1.txt","w+");
	if(fd1 == NULL)
	{
		perror("./1.txt open error\n");
		return -1;
	}
	
	//2.写入47个字符(2个数据块,每块5字节)
	w_ret = fwrite("01234567890123456789012345678901234567890123456", 1, 47,fd1);
	if(w_ret < 47)
	{
		perror("./1.txt write error\n");
	}
	else
	{
		printf("w_ret = %d\n",w_ret);
	}
	
	//3.读取1.txt内容
	if(fseek(fd1, 0, SEEK_SET)==-1)
	{
		perror("./1.txt fseek error\n");
	}
	r_ret = fread(ptr, 5, 2,fd1);
	if(r_ret < 2)
	{
		perror("./1.txt read error\n");
	}
	else
	{
		printf("r_ret = %d\n",r_ret);
	}
	
	//4.打开2.txt内容
	fd2 = fopen("./2.txt","w+");
	if(fd2 == NULL)
	{
		perror("./2.txt open error\n");
		return -1;
	}

	//5.写入2.txt
	w_ret = fwrite(ptr, 5, 2,fd2);
	if(w_ret < 2)
	{
		perror("./2.txt write error\n");
	}
	else
	{
		printf("w_ret = %d\n",w_ret);
	}
	//6.关闭文件
	fclose(fd1);
	fclose(fd2);
}