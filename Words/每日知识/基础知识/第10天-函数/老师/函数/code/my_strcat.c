/*
	调用要定义在被调用之前
	或者,在文件一开始就声明您定义了哪些函数
*/
#include <stdio.h>
#include <string.h>
#define N 100

/*声明一下这个文件中定义了哪些函数*/
//char *my_strcat(char[] ,char[],int); //什么的时候可以不写参数名
char *my_strcat(char a[],char b[],int n);


void print(char a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("-%c-",a[i]);
	}
	
	printf("\n");
}


int main(void)
{
	char a[N] = "abcdefg"; //a数组是用来接收粘贴数据的,
						//要给一个竟可能大的空间,避免数组越界
	char b[] = "qwertyu";
	
	/*调用函数返回什么类型,就应该用什么类型取接收*/
	char* t = my_strcat(a,b,70);
	print(t,78);
	printf("%s\n",t);
}


/*
	my_strcat 是将b字符串粘贴到a字符串后面
		a  表示粘贴到a这个数组
		b  表示要粘贴的是b数组中的元素
		n  表示要粘贴的个数
*/
char * my_strcat(char a[],char b[],int n)
{
	int an = strlen(a);
	int bn = strlen(b);
	int i;
	/*
	for(i=0;i<=bn;i++)   //拷贝整个b字符串
	{
		a[an+i] = b[i]; //b[bn] == '\0'
	}
	*/
	for(i=0;i<n && b[i] != '\0';i++) //拷贝b字符串的前n个
	{
		a[an + i] = b[i];
	}
	a[an + i] = '\0';
	 
	return a;
}
