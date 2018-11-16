/*************************************************************************
	> File Name: testall.c
	> Author: zxl
	> Mail: 
    me: 2018年11月03日 星期六 11时30分19秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include"fcntl.h"
#include"string.h"
#define MAX 500
int main()
{
    int fd ;
    char buf[]="I am *** num:***********";
    char buf1[]="I am *** num:***********";
    char buf2[]="I am ***  num:***********";
    char rd_buf[MAX]={0};
  //  size_t wr_len=0,wr_len1=0,wr_len2=0,rd_len=0,ret;

    //open file
    fd=open("./b.txt",O_CREAT|O_RDWR|O_TRUNC,0777);
    if(fd<0)
    {
        printf("open file b.txt failure\n");
        return -1;
    }
    printf("open file b.txt success\n");
  
    //write file
   write(fd,(char*)buf,sizeof(buf)-1);
  //  printf("wr_len=%d\n",wr_len);
  
    lseek(fd,0,SEEK_END);
    write(fd,(char*)buf1,strlen(buf1));
    lseek(fd,0L,SEEK_END);
    write(fd,(char*)buf2,sizeof(buf2)-1);

    //move position and read file  copy book
    lseek(fd,0,SEEK_SET);
   read(fd,(char*)rd_buf,24);
 //   printf("rd_len=%d\n",rd_len);
    printf("readdata=%s\n",rd_buf);

  //  memset(rd_buf,0,sizeof(rd_buf));
    //
    lseek(fd,0,SEEK_CUR);
    read(fd,(char*)rd_buf,24);
 //   printf("rd_len=%d\nreaddata=%s\n",rd_len,rd_buf);
    printf("readdata=%s\n",rd_buf);
    read(fd,(char*)rd_buf,24);
    printf("readdata=%s\n",rd_buf);
    close(fd);
    return 0;
}
