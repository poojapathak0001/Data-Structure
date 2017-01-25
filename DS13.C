/*
   Name:Pooja Pathak
   Program no:13
   Program Name:WACP to implement ascending priority queue with following functions
		 a. insert  b. serve  c.display (use double pointer).
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<alloc.h>
struct node
{
 int data;
 int pri;
 struct node *link;
};
void insert(struct node**,struct node**);
void serve(struct node**,struct node**);
void display(struct node*);
int main()
{
 struct node *front=NULL,*rear=NULL;
 char ch;
 clrscr();
 while(1)
 {
  printf("\n MENU");
  printf("\n 1.Insert: i");
  printf("\n 2.Serve: s");
  printf("\n 3.Quit: q");
  printf("\n Enter choice:");
  fflush(stdin);
  ch=getchar();
  switch(ch)
  {
   case 'i':
   case 'I': insert(&front,&rear);
	     display(front);
	     break;
   case 's':
   case 'S': serve(&front,&rear);
	     display(front);
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
void insert(struct node **f,struct node **r)
{
 struct node *temp,*q,*q1;
 temp=(struct node *)malloc(sizeof(struct node));
 printf("\n Enter PRIORITY:");
 scanf("%d",&temp->pri);
 printf("\n Enter data:");
 scanf("%d",&temp->data);
 if(*f==NULL)
 {
  *f=temp;
  *r=temp;
  (*f)->link=NULL;
  (*r)->link=NULL;
 }
 else if(temp->pri<(*f)->pri)
 {
  temp->link=*f;
  *f=temp;
 }
 else
 {
  q=*f;
  q1=q->link;
  while((q1!=NULL)&&(q1->pri<=temp->pri))
  {
   q=q->link;
   q1=q1->link;
  }
  temp->link=q1;
  q->link=temp;
  if(temp->link==NULL)
  {
   *r=temp;
  }
 }
}
void serve(struct node **f,struct node **r)
{
  struct node *temp;
  if(*f==NULL)
  {
   printf("\n Empty queue!");
   return;
  }
  else if(*f==*r)
  {
   temp=*f;
   *f=NULL;
   *r=NULL;
  }
  else
  {
   temp=*f;
   *f=(*f)->link;
  }
 free(temp);
}
void display(struct node *f)
{
 struct node *t=f;
 if(f==NULL)
 {
  printf("\n No elements!");
  return;
 }
 else
 {
   printf("\n Priority queue (priority , data):");
   while(t!=NULL)
   { printf(" %d, %d ",t->pri,t->data);
    t=t->link;
   }
 }
}