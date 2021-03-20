#include <stdio.h>
int main()
{
    int x=1024;
    x = x*x%1000;
			x = x*x%1000;
			......
			x = x*x%1000;//第65535次
}