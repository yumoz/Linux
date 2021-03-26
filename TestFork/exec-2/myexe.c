#include<stdio.h>
#include<unistd.h>

int main()
{

  printf("begin ----------------------_\n");
  sleep(1);
  //execl("/usr/bin/ps","ps","-e","-l","-f",NULL);
  //execl("/usr/bin/ls","ls","-al",NULL);
  //etcxeclp("ls","ls","-i","-l","-a",NULL);

  //char *arg[]={
  //  "ls",
  //  "-a",
  //  "-l",
  //  "-i",
  //  NULL
  //};
  
  //execv("usr/bin/ls",arg);
//  execvp("ls",arg);

  char *env[]={
    "myenv = you can see something here!",
    NULL 
  };

  //execle("./mycmd","./mycmd",NULL);
  execle("./mycmd","./mycmd",NULL,env);

  printf("after ----------------------\n");
  return 0;
}
