/*************************************************************************
	> File Name: test.c
	> Author: zxl
	> Mail:1440739448@qq.com 
	> Created Time: 2018年11月09日 星期五 18时58分40秒
 ************************************************************************/

#include<stdio.h>
#include <time.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main()
{
   while(1)
    {
            int q;
            char buf[128];
            printf("please input mode you want:(1cd,2ly,3time)");
            scanf("%d",&q);
            switch(q)
        {

                     int status;
                    case 1:
                  {  pid_t pid1;
                     char *buf1[]={"./gcd",NULL};
                     pid1 =fork();
                     if(pid1<0)
                   {
                       printf("creat child 1 process failed!\n");
                   }
                   else if (pid1 ==0)
                   {
                    printf("child1 process running\n");
                     execvp("./gcd",buf1);
                   }
                   else 
                   {
                      // printf("father process 1  running!\n");
                       waitpid(pid1,&status,0);
                      //    wait(NULL); 
                       printf("father process 1  running!\n");
                   }
                   break;
                  }
                 
                   case 2: 
                     {
                         pid_t pid2;
                         pid2=fork();
                         if(pid2<0)
                         {
                             printf("The child2 is not creat!\n");
                         }
                         else if(pid2 == 0)
                         {
                             printf("child2 process running!\n");
                            execlp("./rn","rn",NULL);
                            exit(1);
                         }
                         else 
                         {
                            waitpid(pid2,&status,0);
                             printf("father process 2  runing\n");
                            // waitpid(pid2,&status,0);
                         }
                         break;
                     }
                   
                     case 3:
                      {

                          pid_t pid3;
                          pid3=fork();
                          if(pid3<0)
                          {
                              printf("Creat child3 process failure\n");
                          }
                          else if (pid3==0)
                          {
                              printf("child3 process runing\n");
                              execl("./show","./show",NULL);
                              exit(2);
                          }
                          else 
                          {
                              printf("father process 3 running\n");
                              wait(NULL);
                          }
                            break;
                        
                      }
                   default :
                       {
                            printf("input wrong!\n");
                            continue;
                       }

                 }
                   fgets(buf,128,stdin);
                   if(!strcmp(buf,"exit\n")) break;
                   memset(buf,0,128);
            
    }

}
