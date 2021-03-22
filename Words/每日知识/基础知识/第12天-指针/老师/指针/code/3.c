#include <stdio.h>
#include <string.h>
/***
int main(void)
{
	int a = 100;
	int *p = &a;
	printf("a:%p  p:%p  &p:%p  &a:%p\n",(int*)a,p,&p,&a);
	//printf("5:%p\n",&(5)); //错
}
***/


void my_strcpy(char *p,char *q)
{
	/**
	*p = *q;  //把q的第一个字母赋值给了 p的第一个地址
	
	*(p+1) = *(q+1);//把q的第二个字符赋值给了 p的第二个地址
	
	......
	if(*q == '\0')
	*/
	//int i = 0; 
	//int j = strlen(p);
	printf("%d\n",strlen(p));
	while(*q != '\0')  //*q != 0
	{
		*(p + strlen(p))  = *q++; //q+i 表示的是q后面第i个地址
		//i++;
		
		//sleep(1);
	}
	
}

int main(void)
{
	char a[100] = {'a','b','c','d','e'};
	char b[20] = "hello world!";
	/*
	for()
	{
		a[i] = b[i];
	}
	*/
	my_strcpy(a,b);
	printf("a:%s\n",a); //----> hello world!
}