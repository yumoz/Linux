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
  cout<<"father before..."<<endl;
  wait(NULL);
  cout<<"father after ..."<<endl;
  }
    return 0;
}
