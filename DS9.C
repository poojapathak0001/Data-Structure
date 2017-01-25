/*
   Name:Pooja Pathak
   Program no:9
   Program Name:WACP to create a circular linked list and then delete any user
		specified node(using double pointer).
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<alloc.h>
struct node
{
 int data;
 struct node *link;
};
void insert(struct node**);
void del(struct node**);
void display(struct node*);
int main()
{
 struct node *start=NULL;
 char ch;
 while(1)
 {
  printf("\n MENU: Circular link list");
  printf("\n 1.Insert : i");
  printf("\n 2.Delete : d");
  printf("\n 3.Quit : q");
  printf("\n Enter choice:");
  fflush(stdin);
  ch=getchar();
  switch(ch)
  {
   case 'I':
   case 'i': insert(&start);
	     display(start);
	     break;
   case 'd':
   case 'D': del(&start);
	     display(start);
	     break;
   case 'q':
   case 'Q': exit(0);
	     break;
   default: printf("\n Invalid choice!");
	     break;
  }
 }
 getch();
 return 0;
}
void insert(struct node **st)
{
 struct node *temp,*q;
 temp=(struct node *)malloc(sizeof(struct node));
 printf("\n Enter data(integer)");
 scanf("%d",&temp->data);
 if(*st==NULL)
 {
  *st=temp;
  (*st)->link=*st;
 }
 else
 {
  q=*st;
  while(q->link!=*st)
  {
    q=q->link;
  }
  q->link=temp;
  temp->link=*st;
 }
}
void del(struct node **st)
{
 struct node *temp,*q,*q1;
 int i,n;
 if(*st==NULL)
 {
  printf("\n List empty!");
  return;
 }
 else
 {
  printf("\n Enter the node to be deleted:");
  scanf("%d",&n);
  q=*st;
  q1=q->link;
  if(n==1)
  {*st=NULL;}
  else
  {
   for(i=0;i<n-2;i++)
   {
     q=q->link;
     q1=q1->link;
   }
   temp=q1;
   q->link=q1->link;
  }
 }
 free(temp);
}
void display(struct node *st)
{
 struct node *temp=st;
 if(temp==NULL)
 {
  printf("\n List empty!");
  return;
 }
 else
 {
  printf("\n LIST:");
  do
  {
   printf("%d ",temp->data);
   temp=temp->link;
  }while(temp!=st);
}
}