#include<stdio.h>
#include<time.h>
int main (void)
	{
		//time_t time(time_t *t);
		//time_t now;
		while(1)
		{
		time_t now;//定义一个时间 变量
		time(&now);//获取系统时间，然后放入now这个变量。
		struct tm *t = localtime(&now);//把&now这个值转换成当地时间，然后定义一个结构体指针指向&now；
		sleep(1);
		printf("%d-%d-%d  星期%d  %d时-%d分-%d秒\n",
		t->tm_year+1900,t->tm_mon+1,t->tm_mday,t->tm_wday,t->tm_hour,t->tm_min,t->tm_sec);
		}
	}	