#include<stdio.h>
#include<conio.h>
void main()
{
    int a[100],i,n,pos,d;
    clrscr();
    printf("\nEnter the size of the array:");
    scanf("%d",&n);
    printf("\nEnter the Array Elements:");
    for(i=0 ; i<n ;i++)
    {
	scanf("%d",&a[i]);
    }
    printf("\nArray Elements before deletion:\n");
    for(i=0;i<n;i++)
    {
	printf("\t%d",a[i]);
    }
    printf("\nEnter the position for Deletion:");
    scanf("%d",&pos);
    d=a[pos];
    for(i=pos;i<n;i++)
    {
        a[i]=a[i+1];
    }
    n--;
    printf("\nArray After Deletion:\n");
    for(i=0;i<n;i++)
    {
        printf("\t%d",a[i]);
    }
    getch();
}
