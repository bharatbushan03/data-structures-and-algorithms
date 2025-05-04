#include<stdio.h>
int main()
{
    int eng,hin,maths,sci,sst;
    printf("Enter the marks of five subjects : ");
    scanf("%d%d%d%d%d",&eng,&hin,&maths,&sci,&sst);

    int total = eng + hin + maths + sci + sst;

    printf("The total marks is %d\n",total);

    printf("The percentage is %f",total/5.0);
    return 0;
}