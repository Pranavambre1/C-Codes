#include<stdio.h>
#include<conio.h>
 void main()
  {
  int a[50],i,j,temp,n,min;
  clrscr();
  printf("How many no's u wants\n");
  scanf("%d",&n);
  printf("Enter the array elements\n");
  for(i=0;i<n;i++)
   {
    scanf("%d",&a[i]);
   }
  for(i=0;i<n;i++)
   {
    min=i;

  for(j=i+1;j<n;j++)
   {
    if(a[j]<a[min])
     {
       min=j;
     }
   }
  temp=a[i];
  a[i]=a[min];
  a[min]=temp;
   }
   printf("Sorted array is\n");
  for(i=0;i<n;i++)
   {
    printf("%d\n",a[i]);
   }

 getch();
}

