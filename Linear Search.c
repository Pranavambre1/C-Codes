#include<stdio.h>
#include<conio.h>
void main()
{
    int a[100],n,i,j,flag=0;
    clrscr();
    printf("\nEnter the size of array:");
    scanf("%d",&j);
    printf("\nEnter the array:\n");
    for(i=0;i<j;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nEnter the element to search:");
    scanf("%d",&n);
    for(i=0;i<j;i++)
    {
         if(a[i]==n)
         {
             flag=1;
             break;
          }
    }
    if(flag==1)
    {
           printf("\n%d  found at :%d",n,i);
    }
    else
    {
           printf("\n%d not found",n);
    }
    getch();
}
