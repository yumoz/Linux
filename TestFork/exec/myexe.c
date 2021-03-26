#include<stdio.h>
#include<unistd.h>

int main()
{

  printf("begin ----------------------_\n");
  sleep(1);
  //execl("/usr/bin/ps","ps","-e","-l","-f",NULL);
  //execl("/usr/bin/ls","ls","-al",NULL);
  execlp("ls","ls","-i","-l","-a",NULL);

  //char *arg[]={
  //  "ls",
  //  "-a",
  //  "-l",
  //  "-i",
  //  NULL
  //};
  
  //execv("usr/bin/ls",arg);
//  execvp("ls",arg);

  printf("after ----------------------\n");
  return 0;
}
