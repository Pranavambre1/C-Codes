
#include<stdio.h>
#include<conio.h>
 void main()
  {
  int i,j,n,temp,a[5];
  clrscr();
  printf("How many no's U wants\n");
  scanf("%d",&n);
  printf("enter the array elements\n");
  for(i=0;i<n;i++)
   {
   scanf("%d",&a[i]);
   }
   for(i=1;i<n;i++)
    {
    temp=a[i];
   for(j=i-1;j>=0;j--)
      {
      if(temp<a[j])
      {
      a[j+1]=a[j];
      a[j]=temp;
     }
     }
     }
   printf("sorted array in\n");
   for(i=0;i<n;i++)
    {
    printf("%d\t",a[i]);
    }

  getch();
 }

