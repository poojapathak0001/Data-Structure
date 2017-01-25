/*
   Name:Pooja Pathak
   Program no:6
   Program Name:WACP to create two linked lists A and B,then create a new linked list
		'S' that contains elements alternately from A and B beginning with the
		first element of A.If you run out of elements in one of the lists,then
		append the remaining elements of the other list to 'S'.
*/
#include<conio.h>
#include<stdio.h>
#include<alloc.h>
struct node
{
 int data;
 struct node *link;
};
void create(struct node**);
void merge(struct node**,struct node **,struct node **);
void display(struct node*);
int main()
{
 struct node *A,*B,*S;
 clrscr();
 printf("\n Creating A");
 create(&A);
 display(A);
 printf("\n Creating B");
 create(&B);
 display(B);
 printf("\n After alternate merging:");
 merge(&A,&B,&S);
 display(S);
 getch();
 return 0;
}
void create(struct node **s)
{
 struct node *temp,*q;
 char choice;
 *s=NULL;
 do
 {
  temp=(struct node*)malloc(sizeof(struct node));
   printf("\n Enter the data:");
   scanf("%d",&temp->data);
   if(temp==NULL)
   {
    q=*s;
    while(q->link!=NULL)
    {
     q=q->link;
    }
    temp->link=q->link;
    q->link=temp;
   }
   else
   {
    temp->link=*s;
    *s=temp;
   }
   printf("\n Do you want to continue (type y or n)?");
   fflush(stdin);
   scanf("%c",&choice);
   fflush(stdin);
}while(choice=='y'||choice=='Y');
}
void display(struct node *s)
{
 struct node *q;
  q=s;
  while(q!=NULL)
  {
   printf("%d ",q->data);
   q=q->link;
  }
}
void merge(struct node **a,struct node **b,struct node **c)
{
 struct node *q1,*q2,*q3,*temp;
 int s=0; *c=NULL;

 q1=*a;q2=*b;
 if(q1==NULL && q2==NULL)
 {
  printf("\n Lists empty:");
  return;
 }
 else
 {
  while(q1!=NULL && q2!=NULL)
  {
   temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
     printf("\n No memory!");
     return;
    }
   if(s==0)
   {
    temp->data=q1->data;
    temp->link=NULL;
    q1=q1->link;
    if((*c)==NULL)
    {
     (*c)=temp;
    }
    else
    {
     q3=*c;
     while(q3->link!=NULL)
      q3=q3->link;
     q3->link=temp;

   }
    s=1;
   }
   else if(s==1)
   {
    temp->data=q2->data;
    q2=q2->link;
    temp->link=NULL;
    if((*c)==NULL)
    {
     (*c)=temp;
    }
    else
    {
    q3=*c;
    while(q3->link!=NULL)
     q3=q3->link;
     q3->link=temp;
    }

    s=0;
   }
 }
}
 if(q1==NULL && q2!=NULL)
 {
  while(q2!=NULL)
  {
   temp=(struct node*)malloc(sizeof(struct node));
   temp->data=q2->data;
   q2=q2->link;
   q3=*c;
   while(q3->link!=NULL)
   q3=q3->link;
   q3->link=temp;
   temp->link=NULL;
  }
 }
 else if(q2==NULL && q1!=NULL)
 {
  while(q1!=NULL)
  {
   temp=(struct node*)malloc(sizeof(struct node));
   temp->data=q1->data;
   q1=q1->link;
   q3=*c;
   while(q3->link!=NULL)
    q3=q3->link;
    q3->link=temp;
    temp->link=NULL;
  }
 }
}