#include <stdio.h>
#include <string.h>

int main(void)
{
	char q[20] = {"hello world!"};
	//char *p = NULL; // NULL表示 空地址,空地址是不能被操作的 (读/写)
	char p[10] = {0};
	int c = 10;
	char t = 'c';
	
	
	strncpy(p,q,7);
	
	printf("q:%s\n",q);
	printf("p:%s\n",p);
}