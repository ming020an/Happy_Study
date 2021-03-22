/**把b[]中字符放a[]中**/
#include<stdio.h>
int my_strcap(char *p ,char *k);
int main (void)
{	
	char a[100]={'a','b','c','d','e'};
	char b[20]="hello world!";
	my_strcap(a,b);
	printf("a:%s\n",a);
}

int my_strcap(char *p ,char *k)
{
	/*while(*k!=0)
	{
		*p=*k;
		p++;
		k++;
	}*/
	if(*k==0)
	return 1;
	else
	{
	*p = *k;
	my_strcap((p +1),(k+1));
	}
}