#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>


int main()
{
  pid_t id = fork();
  if(id<0){
    perror("fork error!\n");
    return 1;
  }
  if(id == 0){
    //child
    int count = 0;
    while(count<10){
      printf("child [%d] is running ...\n",getpid());
      sleep(1);
      count++;
    }
    exit(0);
  }

  //father
  printf("father wait before!\n");
  pid_t ret = waitpid(id,NULL,0);
  if(ret>0){
    printf("wait success!\n");
  }
  else{
    printf("wait failed!\n");
  }
  printf("father wait after!\n");
}
