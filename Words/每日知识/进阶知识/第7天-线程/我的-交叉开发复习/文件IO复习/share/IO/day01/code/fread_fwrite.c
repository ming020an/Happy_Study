#include<stdio.h>
#include <string.h>

int main(void)
{
	int r_ret;
	int cur_offset;
	int end_offset;
	char buf[10] = {0};
	
	FILE *fp1 = fopen("1.txt","r");
	if(fp1 == NULL)
	{
		perror("fopen 1.txt error");
		return -1;
	}

	FILE *fp2 = fopen("2.txt","w");
	if(fp2 == NULL)
	{
		perror("fopen 2.txt error");
		return -1;
	}	
	
	//10 10 10 10 7
	while(1)
	{
		bzero(buf,10);
		cur_offset = ftell(fp1);
		r_ret = fread(buf,5,2,fp1);
		if(r_ret < 2)   //有异常
		{
			if(feof(fp1))  //到达文件尾部
			{
				end_offset = ftell(fp1);
				fwrite(buf,(end_offset-cur_offset),1,fp2);
				break;
			}else if(ferror(fp1))
			{
				printf("fread error\n");
				return -1;
			}
			
		}else{
			fwrite(buf,5,2,fp2);
			printf("fwrite success!\n");
		}
	}
	
	fclose(fp1);
	fclose(fp2);
	return 0;
	
}