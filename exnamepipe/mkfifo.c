/*************************************************************************
	> File Name: mkfifo.c
	> Author: 
	> Mail:
    >function: creat file of pipe
	> Created Time: 2018年11月12日 星期一 10时43分22秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>

int main()
{
    int ret;
    int ret1;
    ret = mkfifo("./a.c",0777);
    ret1 = mkfifo("b.c",0777);

    if(ret<0)
    {
        printf("Creat fifo a.c failure\n");
        return -1;
    }
    printf("creat mkfifo a.c success\n");


    if(ret1<0)
    {
        printf("Creat fifo b.c failure\n");
        return -2;
    }
    printf("creat mkfifo b.c success\n");
    return 0;
}
