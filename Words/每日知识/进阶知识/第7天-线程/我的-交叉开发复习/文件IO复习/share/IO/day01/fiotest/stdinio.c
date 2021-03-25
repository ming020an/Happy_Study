#include<stdio.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>


#define fp1  "/mnt/hgfs/20180710/io/1.text"
#define fp2  "/mnt/hgfs/20180710/io/2.text"

int main()
{
	char buf[47]="abcdefasdfghjkllopijuhygtfreswqazxcvbnmkopliju";
	//建立一个47字符的数组
	FILE *f1,*f2;
	f1=fopen(fp1,"a+");
	if (f1==NULL)
	{
		perror("fopen error");
		return -1;
	}
	//使用fopen打开
	int f_wte=fwrite(buf,47,2,f1);
	if (-1==f_wte)
	{
		perror("fwrite error");
		return -1;
	}
	//写入一个1.text中
	int f_sk=fseek(f1,0,SEEK_SET);
	if (-1==f_sk)
	{
		perror("fseek error");
		return -1;	
	}
	char cun[47]={0};
	int f_red = fread(cun,5,2,f1); 
	if (-1==f_red)
	{
		perror("fread error");
		return -1;
	}
	//使用fread读取，2个数据块，每块5个字节
	int fo2 = open(fp2, O_WRONLY | O_CREAT | O_TRUNC);
	if (-1==fo2)
	{
		perror("fopen error");
		return -1;
	}
	close(fp2);
	//打开2.text
	f2=fopen(fp2,"a+");
	if (f2==NULL)
	{
		perror("fopen error");
		return -1;
	}
	f_wte=fwrite(cun,5,2,f2);
	if (-1==f_wte)
	{
		perror("fwrite error");
		return -1;
	}
	//使用fwrite写入
	printf("%s\n",cun);
	while (1)
	{
		char ch[11];
		ch = fgetc(fp2);
