#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<errno.h>
#include<unistd.h>

void* thread_child(void*);


int main(int argc, char** argv)
{
	printf("enter main\n");
	pthread_t tidc;
	int num;
	int rc=0;
	rc = pthread_create(&tidc, NULL, thread_child, NULL);
	if(rc != 0)
		perror("pthread_child not create:");
	for(num=0;num<10;num++)
	{
		printf("Now,the main num is %d\n",num);
		//sleep(1);	
	}
	
	//pthread_join(tidc, NULL);
	printf("leave main\n");
	exit(0);	
}
void* thread_child(void* arg)
{
	printf("enter thread_child\n");
	int num_c;
	for(num_c=0;num_c<10;num_c++)
	{
		printf("Now,the child num is %d\n",num_c);
		//sleep(1);
	}
	printf("leave thread_child\n");
	pthread_exit(0);
}

 
//gcc pthread.c -o pthread -lpthread
/*
1.注释两个sleep(1)和join，子线程可能还没有运行，主函数就退出了。
2.main中加入sleep是最笨的办法，聪明的办法是pthread_join(tidc, NULL);
*/

