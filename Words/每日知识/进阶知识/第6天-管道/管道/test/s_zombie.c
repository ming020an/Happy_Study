#include <stdio.h>  
#include <unistd.h>  
#include <signal.h>  
#include <sys/types.h>  
#include <sys/wait.h> 
#include <errno.h>  

//合适的方案
   
/*void wait_children(int signo)
{  
  int status;  
  while(waitpid(-1, &status, WNOHANG) > 0);  //在信号处理函数里循环调用waitpid函数来等待所有的退出的子进程
}  
   
int main() {  
   
  int i;  
  pid_t pid;  
   
  signal(SIGCHLD, wait_children);  
   
  for(i=0; i<100; i++) {  
    pid = fork();  
    if(pid == 0)  
      break;  
  }  
   
  if(pid>0) {  
    printf("press Enter to exit...");  
    getchar();  
  }  
   
  return 0;  
}   
*/

//代码会创建100个子进程，但是父进程并未等待它们结束，所以在父进程退出前会有100个僵尸进程。
//#include <stdio.h>  
//#include <unistd.h>  
   
/*
int main() 
{  
   
  int i;  
  pid_t pid;  
   
  for(i=0; i<100; i++) {  
    pid = fork();  
    if(pid == 0)  
      break;  
  }  
   
  if(pid>0) {  
    printf("press Enter to exit...");  
    getchar();  
  }  
   
  return 0;  
} 
*/
 
  //解决方法之一即是编写一个SIGCHLD信号处理程序来调用wait/waitpid来等待子进程返回。
void wait_children(int signo) {  
   
  int status;  
  wait(&status);    
}  
  
int main() {  
   
  int i;  
  pid_t pid;     
  signal(SIGCHLD, wait_children);  
   
  for(i=0; i<100; i++) {  
    pid = fork();  
    if(pid == 0)  
      break;  
  }  
   
  if(pid>0) {  
    printf("press Enter to exit...");  
    getchar();  
  }  
   
  return 0;  
}  
