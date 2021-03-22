#include<stdio.h>
#include<time.h>

/*自己写程序实现date查看时间的功能*/

int main(void)
{
	/*time函数可以帮助我们获取系统的时间*/
	//time_t *now = (time_t*)malloc(sizeof(*now));
	//time(now);
	
	time_t now;
	time(&now); 
	
	/*转换time获取的时间为本地时间,localtime可以帮我们实现*/
	struct tm *t = localtime(&now); 
		//上述步骤已经将时间转换成了 结构体类型的本地时间了
		//并且用 t 指针指向了这个结构体的空间		
	
	/*通过访问结构体成员,可以打印出对应的时间*/
	printf("%d-%d-%d\n",t->tm_year+1900,t->tm_mon+1,t->tm_mday);
	
	return 0;
}