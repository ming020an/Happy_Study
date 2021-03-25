#include <stdio.h>

int main(void)
{
	FILE* fd;
	int ret;
	
	fd = fopen("./1.txt","r+");
	if(fd == NULL)
	{
		printf("open ./1.txt failed!\n");
		return 0;
	}
	
	//fseek(fd,0,SEEK_END);
	char buf[100] = {0};
	fread(buf,20,5,fd);
	
	ret = feof(fd);
	printf("ret = %d\n",ret);
	
	
	
	return 0;
}