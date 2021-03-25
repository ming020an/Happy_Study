#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<errno.h>
#include<unistd.h>

int g_Flag=0;
void* thread1(void*);
void* thread2(void*);

int main(int argc, char** argv)
{
	printf("enter main\n");
	pthread_t tid1, tid2;
	int rc1=0, rc2=0;
	rc2 = pthread_create(&tid2, NULL, thread2, NULL);
	if(rc2 != 0)
		perror("pthread2_not create:");
	rc1 = pthread_create(&tid1, NULL, thread1, &tid2);
	if(rc1 != 0)
		perror("pthread1_not create:");
	//sleep(2);	
	printf("leave main\n");
	exit(0);	
}
void* thread1(void* arg)
{
	printf("enter thread1\n");
	printf("this is thread1, g_Flag: %d, thread id is %u\n",g_Flag, (unsigned int)pthread_self());
	g_Flag = 1;
	printf("this is thread1, g_Flag: %d, thread id is %u\n",g_Flag, (unsigned int)pthread_self());
	//pthread_join(*(pthread_t*)arg, NULL);2退出后1才会退出
	printf("leave thread1\n");
	pthread_exit(0);
}

 void* thread2(void* arg)
{
	printf("enter thread2\n");
	printf("this is thread2, g_Flag: %d, thread id is %u\n",g_Flag, (unsigned int)pthread_self());
	g_Flag = 2;
	printf("this is thread1, g_Flag: %d, thread id is %u\n",g_Flag, (unsigned int)pthread_self());
	printf("leave thread2\n");
	pthread_exit(0);
}

//gcc thread_bs0.c -o thread_bs -lpthread
/*可能的结果
enter main
leave main
（1）main中添加sleep（2）之后的结果：
enter main
enter thread1
this is thread1, g_Flag: 0, thread id is 3067571008
this is thread1, g_Flag: 1, thread id is 3067571008
leave thread1
enter thread2
this is thread2, g_Flag: 1, thread id is 3075963712
this is thread1, g_Flag: 2, thread id is 3075963712
leave thread2
leave main
（2）在线程1退出前加入
pthread_join(*(pthread_t*)arg, NULL);
结果为：
enter main
enter thread1
this is thread1, g_Flag: 0, thread id is 3067607872
this is thread1, g_Flag: 1, thread id is 3067607872
enter thread2
this is thread2, g_Flag: 1, thread id is 3076000576
this is thread1, g_Flag: 2, thread id is 3076000576
leave thread2
leave thread1
leave main
*/

