#include <stdio.h>  //包含头文件
#define PI 3.14
#define FLAG 0

int main(void)
{
	#if FLAG  //预处理,用来选中您要执行哪些代码
			//如果 if后面的值为假,编译之后就没有这代码了
	while(PI) //while(3.14)
	{
		
		int a = 5;
		printf("%d\n",a++);
		sleep(1);
	}
	
	#else
	
	while(1)
	{
		static int a = 5;
		printf("%d\n",a++);
		sleep(1);
	}
	#endif
}