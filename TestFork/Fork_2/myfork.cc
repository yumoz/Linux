#include<iostream>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h> 
#include<stdlib.h>

using namespace std;

int main()
{
  pid_t id = fork();
  if(id<0){
    cerr <<"fork error"<< endl;
    return 1;
  }
  else if(id==0){
    // child
    int count = 0;
    while(1)
    {
      sleep(1);
      cout<<"child ...: "<<count<<endl;
      if(count>=10){
        break;
      }
      count++;
    }
    exit(0);
  }
  else{
    // parent
   int count = 0;
   while(1){
     sleep(1);
     cout<<"father ... : "<<count<<endl;
     if(count ==15){
       wait(NULL);
     }
     count++;
   }
  }
  return 0;
}
