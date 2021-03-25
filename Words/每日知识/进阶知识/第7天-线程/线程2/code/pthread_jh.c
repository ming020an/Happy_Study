#include <pthread.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

void * t_routine(void *data)
{
	printf("data = %p\n",data);

	int b = *((int *)data);
	printf("b = %d\n", b);

	char *p = malloc(1);
	*p = 'A';

	pthread_exit(p);
	//return p;
}


int main()
{
	pthread_t ptid;//用来保存线程ID
	int a = 1024;
	printf("a = %p\n", &a);
	int r = pthread_create(&ptid, NULL,t_routine, (void *)&a);

	//sleep(1);	//main()表示主线程，主线程结束，就表示进程结束了

	char *ret = NULL;
	pthread_join(ptid, (void **)&ret);
	printf("*ret = %c\n",*ret);

	free(ret);

	return 0;
}

#if 0
#include <pthread.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

int share ; //
pthread_mutex_t slock; //线程互斥锁，它存在是为了什么?
					//它为了保护share而存在的

void * routine1(void *data)
{
	pthread_detach(pthread_self());

	char *msg = (char *)data;
	
	pthread_mutex_lock(&slock);//P() //pthread_mutex_lock
	while (*msg != '\0')
	{
		fprintf(stderr, "%c", *msg);
		usleep(100);
		msg++;
	}
	pthread_mutex_unlock(&slock);//V()//pthread_mutex_unlock

	char *p = malloc(sizeof(char));

	*p = 'A';
	pthread_exit(p);
}

int main()
{
	int r;
	pthread_t tid1,tid2; //用来保存新创建的线程ID

	pthread_mutex_init(&slock, NULL); //初始化线程互斥锁

	r = pthread_create(
			&tid1, //第一个参数, pthread_t *,用来保存新线程的ID
			NULL, //第二个参数，为线程属性，NULL则表示采用默认属性
			routine1,// void * (*start_routine) (void *),第三个参数，函数指针，指向线程函数
			"AAAAAAAAAAAAAAAAAAAAA" //第四个参数，将作为线程函数的参数。
	);

	if (r == -1)
	{
		perror("pthread_create error:");
		return -1;
	}

	r = pthread_create(
			&tid2, //第一个参数, pthread_t *,用来保存新线程的ID
			NULL, //第二个参数，为线程属性，NULL则表示采用默认属性
			routine1,// void * (*start_routine) (void *),第三个参数，函数指针，指向线程函数
			"BBBBBBBBBBBBBBBBBBBBBB" //第四个参数，将作为线程函数的参数。
	);

	if (r == -1)
	{
		perror("pthread_create error:");
		return -1;
	}

	char *ret = NULL;

	pthread_join(tid1,(void **) &ret);
	printf("*ret1 = %c\n", *ret);

	pthread_join(tid2,(void **) &ret);
	printf("*ret2 = %c\n", *ret);

	free(ret);

	/*main函数是主线程， 主线程结束，表示进程就是
	结束了，那么在这个进程内的所有其他线程，也就
	over了*/

	pthread_mutex_destroy(&slock);
	pthread_exit(NULL);
}

#endif

