#include<stdio.h>
#include<conio.h>
void main()
{
    int flag=0,lb,ub,i,mid,key,a[100],n;
    clrscr();
    printf("\nEnter the size of array:");
    scanf("%d",&n);
    printf("\nEnter the array elements:\n");
    for(i=0;i<n;i++)
    {
          scanf("%d",&a[i]);
    }
    printf("\nEnter the number for search:");
    scanf("%d",&key);
    lb=0;
    ub=n-1;
    while(lb<=ub)
    {
           mid=(lb+ub)/2;
           if(a[mid]==key)
          {
                                  flag=1;
                    break;
             }
           else if(a[mid]>key)
            {
                               ub=mid-1;
           }
                       else
         {
              lb=mid+1;
          }
    }
    if(flag==1)
    {
	printf("\n%d found at:%d",key,mid);
    }
    else
    {
	printf("\n%d not found",key);
    }
    getch();
}
