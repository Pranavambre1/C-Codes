#include<stdio.h>
#include<conio.h>
#define size 5
int queue[size];
int front=-1;
int rear=0;
void main()
 {
  int choice,item;
  char ans;
  clrscr();
  do
  {
   printf("\n Main Menu");
   printf("\n1.Insert\n2.Delete\n3.Display");
   printf("\n enter U'R choice:\t");
   scanf("%d",&choice);
   switch(choice)
   {
    case 1:
    printf("\n Enter element to be inserted:\t");
	   scanf("%d",&item);
	   insert(item);
	   break;
    case 2:
	   delete();
	   break;
    case 3:
	   display();
	   break;
    default:
	    exit(0);
   }
  printf("\n\n\t Do U want to continue:\t");
  ans=getche();
 }while(ans=='y'||ans=='Y');
getch();
}
  int Qfull()
  {
   if(front==(rear+1)%size)
    return 1;
   else
    return 0;
  }
  int insert(int item)
  {
   if (Qfull())
    printf("\n\t circular queue is full");
   else
    if(front==-1)
     front=rear=0;
   else
    rear=(rear+1)%size;
    queue[rear]=item;
  }

   int Qempty()
   {
    if(front==-1)
     return 1;
    else
     return 0;
   }
   int delete()
   {
    int item;
    if(Qempty())
    printf("\n\t queue is empty");
    else
    {
     item=queue[front];
     if(front==rear)
     {
      front=rear=-1;
     }
    else
     front=(front+1)%size;
     printf("\n Deleted item is== %d",item);
   }
  }
  int display()
  {
   int i;
   if(Qempty())
   {
    printf("\n Queue is empty");
    return 0;
   }
   i=front;
   while(i!=rear)
   {
    printf("\t\t%d",queue[i]);
    i=(i+1)%size;
   }
  printf("\n\t%d",queue[i]);
 }


