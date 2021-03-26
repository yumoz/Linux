#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
  pid_t id = fork();
  if(id<0){
    perror("fork error!\n");
    exit(1);
  }
  if(id == 0){
    //child 
    sleep(3);
    execl("/usr/bin/ls","ls","-a","-l","-i",NULL);
    exit(1);
  }
  pid_t ret = waitpid(id,NULL,0);
  if(ret>0){
    printf("cmd run done... \n");
  }
  return 0;
}
