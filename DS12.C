/*
   Name:Pooja Pathak
   Program no:12
   Program Name:WACP to create a linked list P,then write a C function named split to create two
		  linked lists Q & R from P so that Q contains elements in odd positions
		  of P and R contains the remaining elements.Finally print both lists.
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
struct node *P=NULL;
void insert_P();
void split(struct node **,struct node **);
void display(struct node**);
void quit();
int main()
{
 struct node *Q=NULL,*R=NULL;
 char ch;
 clrscr();
 while(1)
 {
  printf("\n MENU");
  printf("\n 1.Insert in P: i");
  printf("\n 2.Split P: s");
  printf("\n 3.Quit: q");
  printf("\n Enter choice:");
  fflush(stdin);
  ch=getchar();
  switch(ch)
  {
   case 'i':
   case 'I': insert_P();
	     display(&P);
	     break;
   case 's':
   case 'S': split(&Q,&R);
	     printf("\n Q:");
	     display(&Q);
	     printf("\n\n R:");
	     display(&R);
	     break;
   case 'q':
   case 'Q': quit();
	     break;
   default: printf("\n Invalid choice!");
	    break;
  }
 }
 getch();
 return 0;
}
void insert_P()
{
 struct node *temp,*q;
 temp=(struct node*)malloc(sizeof(struct node));
 printf("\n Enter data:");
 scanf("%d",&temp->data);
 temp->link=NULL;
 if(P==NULL)
 {
  P=temp;
 }
 else
 {
  q=P;
  while(q->link!=NULL)
   q=q->link;
  q->link=temp;
 }
}
void split(struct node **q,struct node **r)
{
 struct node *temp,*p1,*q1,*r1;
 int i=-1;
 p1=P;
 while(p1!=NULL)
 {
  i++;
  if(i%2!=0)
  {
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=p1->data;
    temp->link=NULL;
    if(*q==NULL)
    {
     *q=temp;
    }
    else
    {
     q1=*q;
     while(q1->link!=NULL)
      q1=q1->link;
      q1->link=temp;
    }
  }
  else
  {
   temp=(struct node *)malloc(sizeof(struct node));
   temp->data=p1->data;
   temp->link=NULL;
   if(*r==NULL)
   {
    *r=temp;
   }
   else
   {
    r1=*r;
    while(r1->link!=NULL)
     r1=r1->link;
    r1->link=temp;
   }
  }
  p1=p1->link;
 }
}
void display(struct node **t)
{
 struct node *tmp;
 tmp=*t;
 if(tmp==NULL)
 {
  printf("\n List empty!");
  return;
 }
 else
 {
  while(tmp!=NULL)
  {
   printf("%d ",tmp->data);
   tmp=tmp->link;
  }
 }
}
void quit()
{exit(0);}