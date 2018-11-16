/*************************************************************************
	> File Name: server.c
	> Author: 
	> Mail: 
	> Created Time: 2018年11月12日 星期一 10时46分52秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdlib.h>
#include<string.h>

int main()
{
   // pid_t pid;
   // pid=fork();
    int fd,fd1;
    int status;
    char wrbuf[128];
    char rdbuf[128]={0};
    fd=open("./a.c",O_RDONLY);
    fd1=open("./b.c",O_WRONLY);
while(1)
{ 
    pid_t pid;
    pid=fork();
    if(pid<0)
    {
        printf("creat fork failure\n");
        return -1;
    }
    else if(pid>0)  //father process
    {
        printf("father process running\n");
        printf("server start read:\n");
        read(fd,rdbuf,128);
        printf("recv from fifo data:%s",rdbuf);
    //    waitpid(pid,&status,WNOHANG);
    }
    else 
    {
        printf("child process running\n");
        memset(wrbuf,0,sizeof(wrbuf));
        fgets(wrbuf,128,stdin);
        write(fd1,wrbuf,strlen(wrbuf));
      //  exit(0);
    }
    if(fd<0)
    {
        printf("open fifo a.c failure\n");
        return -1;
    }

    if(fd1<0)
    {
        printf("open fifo b.c failure\n");
        return -2;
    }
    
    if(!strcmp(rdbuf,"quit\n"))
    break;
    memset(rdbuf,0,128);
}
    sleep(1);
    close(fd);
    close(fd1);
    return 0;
}
