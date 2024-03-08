#include<stdio.h>
#include<conio.h>
#define size 100
int stack[size];
int top;

void push(int num)
{
top++;
stack[top] =num;
}
int pop()
{
int val;
val=stack[top];
top--;
return val;
}
void main()
{
int i,val,n,a[10];
clrscr();
printf("enter number of element in stack array");
scanf("%d",&n);
for(i=0;i<n;i++)
{

scanf("%d",&a[i]);
}
for(i=0;i<n;i++)
{
push(a[i]);
}
for(i=0;i<n;i++)
{
val=pop();
printf("%d",val);
}
getch();
}
