/*************************************************************************
	> File Name: client.c
	> Author: 
	> Mail: 
	> Created Time: 2018年11月12日 星期一 10时52分28秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>

int main()
{
  //  pid_t pid1;
  //  pid1= fork();
    int fd,fd1;
    int status;
    char rdbuf[128]={0};
    char wrbuf[128];
    fd=open("./a.c",O_WRONLY);
    fd1=open("./b.c",O_RDONLY);
while(1)
{
    pid_t pid1;
    pid1=fork();
    if(pid1<0)
    {
        printf("creat fork porcess failure\n");
        return -1;
    }
    else if(pid1>0)
    {
      
        read(fd1,rdbuf,128);
        printf("recv from fifo data:%s",rdbuf);
      //  waitpid(pid1,&status,WNOHANG);

    }
    else 
    {
       
        printf("father process runing\n");
      //  printf("client start write:\n");
        memset(wrbuf,0,sizeof(wrbuf));
        fgets(wrbuf,128,stdin);
        write(fd,wrbuf,strlen(wrbuf));
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
       
    if(!strcmp(wrbuf,"quit\n"))
    {
        break;
    }
     memset(rdbuf,0,128);
 }
    sleep(1);
    close(fd);
    close(fd1);
    return 0;
}
