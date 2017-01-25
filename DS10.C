/*
   Name:Pooja Pathak
   Program no:10
   Program Name:WACP to delete duplicate name(if any) from single link list.The information
		field of each node should contain name(single word name) and roll no of students.
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<alloc.h>
struct node
{
 char name[20];
 int r_no;
 struct node *link;
};
struct node *start=NULL;
void insert();
void del_dup();
void display();
int main()
{
 char ch;
 clrscr();
 while(1)
 {
  printf("\n\n MENU");
  printf("\n 1.Insert: i");
  printf("\n 2.Delete duplicate: d");
  printf("\n 3.Quit: q");
  printf("\n Enter choice:");
  fflush(stdin);
  ch=getchar();
  switch(ch)
  {
   case 'i':
   case 'I': insert();
	     display();
	     break;
   case 'd':
   case 'D': del_dup();
	     display();
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
void insert()
{
 struct node *temp,*q;
 temp=(struct node *)malloc(sizeof(struct node));
 printf("\n Enter name:");
 scanf("%s",&temp->name);
 printf("\n Enter roll no:");
 scanf("%d",&temp->r_no);
 temp->link=NULL;
 if(start==NULL)
 {
  start=temp;
 }
 else
 {
  q=start;
  while(q->link!=NULL)
  {
    q=q->link;
  }
  q->link=temp;
 }
}
void del_dup()
{
 struct node *temp,*q,*q1,*q2;
 q=start;
 while(q!=NULL)
 {
  q1=start;
  q2=q1->link;
  while(q2!=NULL)
  {
   while(((strcmp(q->name,q2->name)!=0)||(q==q2))&&q2!=NULL)
   {
    q1=q1->link;
    q2=q2->link;
   }
   if(q2!=NULL)
   {temp=q2;
   q1->link=q2->link;
   q2=q2->link;
   free(temp);
  }}
  q=q->link;
 }
}
void display()
{
 struct node *temp;
 temp=start;
 if(temp==NULL)
 {
  printf("\n List empty!");
  return;
 }
 else
 {
  printf("\n Details:");
  while(temp!=NULL)
  {
   printf("\n\n Student name:%s",temp->name);
   printf("\n Student roll_no:%d",temp->r_no);
   temp=temp->link;
  }
 }
}