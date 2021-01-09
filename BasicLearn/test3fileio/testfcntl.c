/*
 
*/
#include <stdio.h>
#include <sys/types.h>  
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#define MAX_SIZE 1000  
int main(int argc,char* arg[])
{
    int fd;
 // ssize_t length_w,length_r = MAX_SIZE,ret;
    ssize_t ret;
    char *testwrite ="hello.txt";
//  ssize_t count;
	char buffer_write1[] = "This is ***  Schoolnumber:***********\n";
	char buffer_write2[] = "This is *** Schoolnumber:***********\n";
	char buffer_write3[] = "This is ***  Schoolnumber:***********\n";
	char buffer_read[MAX_SIZE]={0};						

	if((fd = open(testwrite,O_RDWR|O_CREAT|O_TRUNC,0777))<0)
    {
        printf("open %s failed\n",testwrite);
	}
	fcntl(fd,F_SETFL,O_APPEND);
    write(fd,buffer_write1,strlen(buffer_write1));//write
	write(fd,buffer_write2,strlen(buffer_write2));
	write(fd,buffer_write3,strlen(buffer_write3));
	close(fd);
	if((fd = open(testwrite,O_RDWR|O_CREAT,0777))<0)
    {
		printf("open %s failed!\n",testwrite);
	}
	if((ret = read(fd,buffer_read,MAX_SIZE-1))<0)
    {
		perror("read");
	}
	buffer_read[ret]=0;			
    printf("Files Content is:\n%s \n",buffer_read);
	close(fd);
    return 0;									
}   
