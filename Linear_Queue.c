#include<stdio.h>
#include<conio.h>
#define size 5
struct queue
 {
  int que[size];
  int front,rear;
 }Q;
void main()
{
 int choice,item;
 char ans;
 clrscr();
 Q.front=-1;
 Q.rear=-1;

 do
 {
  printf("\n================main menu===============\n");
  printf("\n1.insert\n2.delete\n3.display");
  printf("\n enter U'R choice::");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1:if(Qfull())
	  printf("\n Queue full cant insert ele");
	  else
	  {
	   printf("\n\t enter ele to be inserted::");
	   scanf("%d",&item);
	   insert(item);
	  }
	  break;
   case 2:if(Qempty())
	  printf("\n\t Queue is empty");
	  else
	  delete();
	  break;
   case 3:if(Qempty())
	  printf("\n\t Queue is empty");
	  else
	  display();
	  break;
   default:printf("\n Wrong choice");
	   break;
  }
   printf("\n do U want to continue::");
   ans=getche();
 }while(ans=='y'||ans=='Y');
}
 int Qfull()
  {
   if(Q.rear>=size-1)
   return 1;
   else
   return 0;
  }
 int insert(int item)
  {
   if(Q.front==-1)
   Q.front++;
   Q.que[++Q.rear]=item;
   return Q.rear;
  }
 int Qempty()
  {
   if((Q.front==-1)||(Q.front>Q.rear))
   return 1;
   else
   return 0;
  }
 int delete()
  {
   int item;
   item=Q.que[Q.front];
   Q.front++;
   printf("\n deleted item is== %d",item);
   return Q.front;
  }
 int display()
  {
   int i;
   for(i=Q.front;i<=Q.rear;i++)
   printf("\t\t%d",Q.que[i]);
  }




























