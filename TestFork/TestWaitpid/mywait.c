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
    while(count<4){
      printf("child [%d] is running ...\n",getpid());
      sleep(1);
      count++;
    }
    exit(0);
  }

  //father
  printf("father wait before!\n");
  int st = 0;
  pid_t ret = waitpid(id,&st,0);
  if(ret>0){
    printf("wait success!\n");
    printf("st ； %d\n ", st);
    printf("child signal :%d\n",st & 0x7F);//111 1111
    printf("child exit code: %d\n",(st>>8)&0xff);
    if(st & 0x7F){
      printf("child run error!\n");
    }
    else{
      int code = ((st>>8)&0xff);

      if(code){
        printf("child run success,but result is note right!；code : %d\n",code);
      }
      else{
        printf("child run success ,result is right! :code :%d\n",code);
      }
    }
  }
  else{
    printf("wait failed!\n");
  }
  printf("father wait after!\n");
}
