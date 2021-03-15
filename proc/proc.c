#include"proc.h"

void proc()
{
  int i=0;
  char buf[NUM];

  memset(buf,'\0',sizeof(buf));
  
  const char* lable="|/-\\";
  
  while(i<100)
  {
    fflush(stdout);
    buf[i++]='#';
    usleep(30000);
    printf("[%-100s][%3d%%][%c]\r",buf,i,lable[i%4]);
  }
  printf("\n");
}
 
