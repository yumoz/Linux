#include<stdio.h>
#include<stdlib.h>

int rn(int year)
{
    return (year%400==0 || (year%4==0 && year%100!=0))? 1 : 0;
}

/*
int main(int agrc,char* agrv[])
{
    if(agrc!=2)
    {
        
        perror("input faild");
        exit(1);
    }
    int a=atoi(agrv[1]);
    
    if(rn(a)==1) printf("This is leap year!\n");
    else printf("It is not leap year!\n");
   // printf("%d\n",rn(a));
    return 0;
}
*/
int main()
{
    int a;
    printf("please input year:");
    scanf("%d",&a);
    if(rn(a)==1) printf("This is leap year!\n");
    else printf("It is not leap year!\n");
   // printf("%d\n",rn(a));
    return 0;
}


