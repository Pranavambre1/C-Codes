#include<stdio.h>
#include<conio.h>
void main()
{
    int a[100],n,i,pos;
    clrscr();
    printf("Enter the size of array: ");
    scanf("%d",&n);
    //input
    printf("\nEnter Array Element:");
    for(i=0; i<n ;i++)
    {
	scanf("%d",&a[i]);
    }
    //Output
    printf("\nArray Elements:");
    for(i=0 ; i<n ; i++)
    {
	printf("\t%d",a[i]);
    }
    printf("\nEnter the Position For Inserting the number:");
    scanf("%d",&pos);
    //Shifting of array
    for(i=n-1 ; i>=pos ; i--)
    {
	a[i+1]=a[i];
    }
    printf("\nEnter the number in the position :");
    scanf("%d",&a[pos]);
    n++;
    for(i=0 ; i<n ; i++)
    {
	printf("\t%d",a[i]);
    }
    getch();
}
