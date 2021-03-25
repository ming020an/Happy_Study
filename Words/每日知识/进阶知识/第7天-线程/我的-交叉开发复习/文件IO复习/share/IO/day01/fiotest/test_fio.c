#include <stdio.h>
#include <errno.h>
#include <string.h>



int main(int argc,char* argv[])
{
	//打开1.txt
	FILE *fp1 = fopen("./1.txt","w+");
	if(fp1 == NULL)
	{
		perror("fopen 1.txt fail!");
		return -1;
	}
	
	
	//在1.txt里写入47个字符
	char buf1[50] ={"qwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyu"};
	int r_fw1 = fwrite(buf1,1,47,fp1);
	printf("r_fw1 = %d\n",r_fw1);
	
	//打开2.txt
	FILE *fp2 = fopen("./2.txt","w");
	if(fp2 == NULL)
	{
		perror("fopen 2.txt fail!");
		return -1;
	}
	
	//从1.txt里按要求读取数据
	fseek(fp1,0,SEEK_SET);
	char buf2[128] ={0};
	int r_fr1 = fread(buf2,5,2,fp1);
	if(r_fr1 < 2)
	{
		if(!feof(fp1))
		{
			printf("fread error!");
			return -1;
		}
		else
		{
			printf("the file end!\n");
		}
	}
	printf("the fread string is : %s\n",buf2);
	
	//将数据存入2.txt
	int r_fw2 = fwrite(buf2,1,strlen(buf2),fp2);
	printf("r_fw2 = %d\n",r_fw2);
	
	//关闭1.txt与2.txt
	fclose(fp1);
	fclose(fp2);
	
	return 0;
	
}