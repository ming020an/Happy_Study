#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <time.h>
#include<string.h>
#include <dirent.h>
//读取目录中.bmp文件
//记录文件名存放在数组中
//放到Lcd显示
//
//
//
//
//
/*typedef struct fileNode
	{
		char filename[256];
		struct fileNode *next
	}Fnod;
				
typedef struct LinkedList
	{
		struct fileNode *first;
		struct fileNode *last;
	}Link;
	
	Link*creat_list(void)
	{
			//定义一个头结点指针,分配空间
		Link *list = (Link*)malloc(sizeof(*list));
		list->first = NULL;
		list->last = NULL;
		return list;
	}
	
	Link * creat_link(LIST* list)//创建结点链表
		{
			Link*list=Link*creat_list();

			while(1)
			{
				Fond *p = (Fond*)malloc(sizeof(*p));//暂时用p做介质连链表
				p->next=NULL;
				if(list->first==NULL)//判断是否有链表
				{
					list->first = p;
					list->last = p;
				}
				else
				{
					list->last->next = p;
					list->last = p;
				}
					
			}
			return list;
		}
*/
//识别目录文件中bmp，jpg文件,未实现
int dir_recog(const char *pathname)
{
	int sum=0;
	DIR *dir = opendir(pathname);//打开文件
	if (dir == NULL)
	{
		perror("opendir error:");
		return 0;
	}

	struct dirent *dirp = NULL ;

	while (dirp = readdir(dir))//读一个目录文件中所有文件
	{
		
		if (strcmp(dirp->d_name, ".") == 0 || 
			strcmp(dirp->d_name, "..") == 0)
		{
			continue;
		}
	//
		char filename[512];//定义一个字符串数组存放所有的文件
		sprintf(filename, "%s/%s", pathname, dirp->d_name);
		printf("filename:%s\n",filename);
		struct stat st;
		int len;//定义一个变量接收文件名的长度
		char *bm;
			printf("len=%d bm=%s\n",len,bm);//如果不是bmp接着读文件，是bmp打印出来
			
			stat(filename, &st);//读取文件的状态
			if(S_ISREG(st.st_mode))
			{
				len=strlen(filename);
				bm=(filename+(len-4));
				if(strcmp(bm,".bmp"))
				{
					continue;
				}
				else
				printf("%s \n ", dirp->d_name);
			
			}
			else if(S_ISDIR(st.st_mode))
			{
				sum+= dir_recog(filename);
		
			}
		

		return sum;
	}
}

int main (int argc,char *argv[])
	{
		int sum;
		DIR *dir;
		dir = opendir(argv[1]);//输入你需要打开目录文件参数
		
		if (dir == NULL)
		{
			perror("opendir error");
			return -1;
		}
		struct dirent *dirp = NULL;
		sum=dir_recog(argv[1]);
		printf("sum=%d\n",sum);
		return 0;
	}

