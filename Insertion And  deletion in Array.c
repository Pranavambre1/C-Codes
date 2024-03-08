             #include<stdio.h>
            #include<conio.h>
            void main()
           {
    int a[100],n,pos,i,ch,del_e;
    char c;
    clrscr();
    do{
    printf("\nEnter the size of the array:");
    scanf("%d",&n);
    printf("\nEnter the Array Elements:\n");
    for(i=0;i<n;i++)
    {
                             scanf("%d",&a[i]);
    }
    printf("\nArray before operation:\n");
    for(i=0;i<n;i++)
    {
               printf("\t%d",a[i]);
    }
    start:
                          printf("\nWhich operation do you want to do:\n1.Insertion\n2.Deletion\n");
                          scanf("%d",&ch);
          if(ch==1)
         {
                 printf("\nEnter the position where you want to insert new value:");
                               scanf("%d",&pos);
                               for(i=n;i>=pos;i--)
                {
                               a[i+1]=a[i];
                              }
               n++;
                             printf("\nEnter the new value:");
                             scanf("%d",&a[pos]);
              printf("\nArray after insertion:\n");
                            for(i=0;i<n;i++)
                           {
                        printf("\t%d",a[i]);
            }
                }
 else if(ch==2)
 {
               printf("\nEnter the position for deletion:");
               scanf("%d",&pos);
                             del_e=a[pos];
              for(i=pos;i<n;i++)
                            {
                        a[i]=a[i+1];
              }
                  n--;
                               printf("\nArray after deletion:\n");
                for(i=0;i<n;i++)
               {
                             printf("\t%d",a[i]);
                }
   }
                else
              {
          printf("\nYou enter wrong");
                        goto start;
               }
               printf("\nDo you want to try again:\nYes\nNO\n");
               scanf("%s",&c);
}while(c=='y'||c=='Y');
getch();
}
