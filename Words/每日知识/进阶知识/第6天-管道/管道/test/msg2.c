#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
	   

#define  PATHNAME "/home/gec"
#define  PROJ_ID    143


//sizeof(struct msgbuf) = sizeof(mtype) ＝ 4
struct msgbuf
{
	long mtype;
	char mtext[1024];
};


int main()
{
	key_t key;


	//生成一个system v ipc的key
	key = ftok(PATHNAME, PROJ_ID);
	if (key == -1)
	{
		perror("ftok error");
		return -1;
	}


	//打开一个 system v消息队列
	int msg_id = msgget(key, IPC_CREAT | 0664);
	if (msg_id == -1)
	{
		perror("msgget error:");
		return -1;
	}



	struct msgbuf buf;

	int r = msgrcv(msg_id, &buf, 1024, 0/*消息类型，0为任意类型*/, 0);
	if (r > 0)
	{
		printf("type: %ld\n", buf.mtype);
		printf("data:%s\n", buf.mtext);
	}
	
}
