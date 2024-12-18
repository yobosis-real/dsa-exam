#include<stdio.h>
void main()
{
    int *pt[10];
    int a[10]={0,1,2,3,4,5,6,7,8,9};
    pt[0]=&a[0];
    for(int i=0;i<10;i++)
    {
        pt[i]=&a[i];
    }
    for(int i=0;i<10;i++)
    {
        printf("%d\t",&a[i]);
    }
    printf("\n");
    for(int i=0;i<10;i++)
    {
        printf("%d\t",*pt[i]);
    }
}