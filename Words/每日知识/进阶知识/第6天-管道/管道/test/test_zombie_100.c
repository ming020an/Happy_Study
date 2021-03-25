#include <stdio.h>  
#include <unistd.h>     

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