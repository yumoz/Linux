#include<iostream>
#include<string.h>

using namespace std;

int main(int argc,char *argv[],char *env[])
{
  for(int i=0;i<argc;i++){
    cout<<"argv["<<i<<"]"<<":"<<argv[i]<<endl;
  }
  string s = argv[1];
  if(s == "-a"){
    cout<<"hello a"<<endl;
  }
  else{
  cout<<"hello b"<<endl;
  }
  return 0;
}
