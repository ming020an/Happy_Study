//#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
int a=100;

int main(int argc,char *argv[])
{
	/*****************fork-1*************/
#if 0
    pid_t pid = fork();
    if (pid == -1)
	{
		perror("fork() error");
		return -1;
	}
    printf("%d\n",pid);	//说明调用一次返回
#endif  

/*****************fork-2*************/
//子进程copy了父进程的数据和指令
//
#if 0
int money=20;
pid_t pid = fork();
    if (pid == -1)
	{
		perror("fork() error");
		return -1;
	}
	else if(pid>0)
	{
		
		printf("I AM FATHER, MY PID IS %d,MY FATHER PID IS %d,MY SON IS %d \n",getpid(),getppid(),pid);
		//printf("I HAVE %d YUAN\n",money);
		sleep(2);
		
	}	
	else if(pid==0)
	{
		printf("I AM SON ,MY PID IS %d,MY FATHER PID IS %d \n",getpid(),getppid());
		//printf("MY FATHER GIVE ME %d YUAN\n",money);
	}
#endif
/*****************test-1*************/
#if 0
	int money=20;
	//printf("YESTODAY IS A NICE DAY!\n");//信息输出到标准的输出设备（显示器），并且清空缓冲区。
	printf("YESTODAY IS A NICE DAY!");//信息在缓冲区，直到遇到\n，输出到标准的输出设备（显示器）
	pid_t pid = fork();	
	if (pid == -1)
	{
		perror("fork() error");
		return -1;
	}
    else if(pid > 0)
    {
    	printf("I AM FATHER ,MY SON IS%d \n",pid);
		printf("I HAVE %d YUAN\n",money);
		sleep(1);	
    }
	else if(pid == 0)
    {
    	printf("I AM SON,HELLO EVERYONE! \n");
		printf("MY FATHER GIVE ME %d YUAN\n",money);
    	
    }
	printf(" TODAY IS A NICE DAY! I AM %d\n",getpid());//输出两次，父进程的指令，数据都被克隆到子进程中了

#endif

/*****************fork-3*************/
//说明：如果父进程先死掉，那么子进程就会变为孤儿进程，有进程组的老大代养.
#if 0
	pid_t pid = fork();
	if (pid == -1)
	{
		perror("fork() error");
		return -1;
	}
    //printf("%d\n",getppid());
   else if(pid == 0)
    {
    	printf("pid = 0: pid = %d  ppid = %d\n",getpid(),getppid());
		sleep(5);
    }
	else if(pid > 0)
    {
    	printf("pid > 0: pid = %d  ppid = %d\n",getpid(),getppid());
        }
#endif

/*****************fork-4*************/
//说明：fork成功创建了进程，复制了共有的东西，一旦fork成功后进程间是独立的，互不影响
#if 0
   	int b = 20;
	int *p = malloc(sizeof(int));
	*p = 30;

	pid_t pid = fork();
	if (pid == -1)
	{
		perror("fork() error");
		return -1;
	}
    else if(pid == 0)
    {
    	//sleep(1);
    	printf("a = %d b = %d *p = %d\n",a, b, *p);
    	printf("I AM SON,MY PID IS: %d  MY FATHER PID IS = %d\n",getpid(),getppid());
    }
	else if(pid > 0)
    {	
    	a = 300;
    	b = 200;
    	*p = 300;
    	printf("a = %d b = %d *p = %d\n",a, b, *p);
    	printf("I AM FATHER ,MY PID IS %d MY FATHER PID IS %d\n",getpid(),getppid());
		sleep(3);	
    }
    
    printf("hahahahaha\n");
    return 0;
#endif
/***************fork++****************/
//循环创建fork
#if 0
	int i;
	for(i=0;i<2;i++)
	{
		pid_t pid = fork();
		if (pid == -1)
		{
			perror("fork() error");
			return -1;
		}
       else if(pid == 0)
		{
			printf("pid = 0: pid = %d  ppid = %d\n",getpid(),getppid());
		}
		else if(pid > 0)
		{
			printf("pid > 0: pid = %d  ppid = %d\n",getpid(),getppid());
        }
	}
#endif

    /***************exit****************/
#if 0
    printf("123456789");
   // _exit(0);	//不做清理工作
     exit(0);	//清理
#endif

    /***************wait****************/
#if 0
    pid_t pid = fork();
    if (pid == -1)
	{
		perror("fork() error");
		return -1;
	}
    if(pid == 0)
    {
    	printf("I AM SON : pid = %d  ppid = %d\n",getpid(),getppid());
    	exit(6);
    }
	if(pid > 0)
    {
    	printf("I AM FATHER: pid = %d  ppid = %d\n",getpid(),getppid());
    	
    	int status;

		wait(&status); //等待子进程状态发生改变，会引起调用进程阻塞

		if (WIFEXITED(status))
		{
			printf("status: %d\n", WEXITSTATUS(status));
		}
    }
#endif

/***************exec****************/
#if 1
    pid_t pid = fork();
    if (pid == -1)
	{
		perror("fork() error");
		return -1;
	}
    if(pid == 0)
    {
    	printf("haizi: pid = %d  ppid = %d\n",getpid(),getppid());
    	int r;
		//r = execl("./sum", "sum","6", "4", NULL);
		//char *pa = "456";
		//execl("./sum_zl", "sum_zl",pa, "4", NULL);
		
		//r = execlp("ls","ls","-l",NULL);	//执行命令
		
		char * args[] ={"sum_zl", "3", "4", NULL};
		//r = execv("./sum_zl", args);
		//r = execvp("sum_zl", args); //在PATH指定的路径下去找sum_zl
		
		char *envp[] ={"A=1", "B=2", "C=3", NULL};
		r = execvpe("./sum", args, envp);
		
		if (r == -1)
		{
			perror("exec error:");
			exit(4);
		}

		printf("exec success\n"); //这行代码，永远不会被执行，you know de 
    }
	if(pid > 0)
    {
    	printf("baba: pid = %d  ppid = %d\n",getpid(),getppid());
    	
    	int status;

		wait(&status); //等待子进程状态发生改变，会引起调用进程阻塞

		if (WIFEXITED(status))
		{
			printf("status: %d\n", WEXITSTATUS(status));
		}
    }
#endif
    
}