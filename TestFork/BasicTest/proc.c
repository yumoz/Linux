#include<stdio.h>
#include<unistd.h>

int main()
{

  printf("print once \n");

  pid_t ret = fork();
  if(ret>0){
    while(1){
    printf("I am parent ! pid is:%d\n",getpid());
    sleep(1);
  }
  }
  else if(ret == 0){
    while(1){
      printf("I am child ! pid is :%d ,ppid is: %d\n",getpid(),getppid());
      sleep(2);
    }
  }

  else{
    printf("fork error\n");
  }
  sleep(1);
  return 0;
}
