#include <stdio.h>
#include <string.h>

int main(void)
{
	char buf[100] = "abc\0defghijklmn";  // {0};
	printf("strlen:%d\n",strlen(buf));
	printf("sizeof is :%d\n",sizeof(buf));
	
	memset(buf,0,20); // 等同于  bzero(buf,20);
	
	printf("memset end\n");
	printf("strlen:%d\n",strlen(buf));
	printf("sizeof is :%d\n",sizeof(buf));
	printf("%s\n",buf);
	
	return 0;
}