#include<stdio.h>
#include<conio.h>
void input(int [],int);
void output(int [],int);
void logic(int [],int,int,int);
void search()
{
    int a[5],key,i,flag=0;
    input(a,5); //taking input of Array
    output(a,5); //displaying Array before searching
    logic(a,5,key,flag); //logic of searching techniques
}
//input of Array
void input(int a[],int n)
{
    int i;
    printf("\nEnter the Array elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
//output of Array Before Searching
void output(int a[],int n)
{
    int i;
    printf("\nArray element is:");
    for(i=0;i<n;i++)
    {
            printf("\t%d",a[i]);
    }
}
//logic of Linear Search and Binary Search
void logic(int a[],int n,int key,int flag)
{
    int ch,i;
    int lb,ub,mid;
    printf("\nEnter the number you want to search:");
    scanf("%d",&key);
    searchtech:
	printf("\nWhich method do you like to do:");
	printf("\n1.Linear search\n2.Binary Search");
	scanf("%d",&ch);
    switch(ch)
    {
	case 1:
	    for(i=0;i<n;i++)
	    {
		if(a[i]==key)
		{
		    flag=1;
		    break;
		}
	    }
	    if(flag==1)
	    {
		printf("\n%d found at:%d",key,i);
	    }
	    else
	    {
		printf("\n%d not found",key);
	    }
	    break;
	case 2:
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
		printf("\n%d not found ",key);
	   }
	   break;
	default:
	    printf("\nYou entered wrong value please try again");
	    goto searchtech;
    }
}

void main()
{
    clrscr();
    search();
    getch();
}
