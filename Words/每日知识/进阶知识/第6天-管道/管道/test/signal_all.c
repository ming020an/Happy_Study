#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
void sig_zj(int signum);
int flag = 0;
int main()
{
	int sig;
#if 0
	scanf("%d",&sig);
	kill(sig,SIGKILL);
	printf("11111\n");
#endif

#if 0
	// kill(getpid(),SIGINT);
	// while(1)
	// 	printf("11111\n");
	
	int r = raise(SIGINT);
	if(r == -1)
	{
		perror("raise error");
		return -1;
	}
	while(1)
	 	printf("11111\n");
#endif

#if 1
	// alarm(3);
	// while(1)
	// {
	// 	printf("11111\n");
	// }

	alarm(3);
	pause();
	while(1)
	{
		printf("11111\n");
	}
#endif
//重新定义SIGINT 
#if 0
	signal(SIGINT,sig_zj);
	signal(SIGTSTP,sig_zj);
	signal(SIGALRM,sig_zj);
	alarm(8);
	while(1)
	{
		if(flag == 1)
			printf("%d\n",flag);
		if(flag == 2)
			printf("%d\n",flag);
		if(flag == 8)
		{
			printf("%d\n",flag);
			break;
		}
	}
#endif
}

void sig_zj(int signum)
{
	switch(signum)
	{
		case SIGINT:
			flag = 1;
			break;
		case SIGTSTP:
			flag = 2;
			break;
		case SIGALRM:
			flag = 8;
		default:
			break;
	}
}