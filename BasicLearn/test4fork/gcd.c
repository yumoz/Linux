#include<stdio.h>
#include<stdlib.h>

int gcd(int n,int m)
{
    return n%m==0 ?m:gcd(m,n%m);
}

int main()
{
    int a,b;
    printf("please input two num:");
    scanf("%d %d",&a,&b);
    printf("common divisor is:%d\n",gcd(a,b));
    return 0;
}
/*
int main(int agrc,char* agrv[])
{
    if(agrc!=3)
    {
        perror("input faild");
        exit(1);
    }
    int a=atoi(agrv[1]);
    int b=atoi(agrv[2]);
    printf("common divisor is:%d\n",gcd(a,b));
    return 0;
}
*/
