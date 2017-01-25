/*
   Name:Pooja Pathak
   Program no:8
   Program Name:WACP to insert and delete elements from a queue using link list,
		each node should have the following information about a student
		s_roll_no,s_name(single word name),s_grade.
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<alloc.h>
struct node
{
 int s_roll_no;
 char s_grade;
 char s_name[20];
 struct node *link;
};
struct node *front=NULL,*rear=NULL;
void insert();
void del();
void display();
int main()
{
 char ch;
 clrscr();
 while(1)
 {
  printf("\n MENU");
  printf("\n 1.Insert: i");
  printf("\n 2.Delete: d");
  printf("\n Quit: q");
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
   case 'D': del();
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
 struct node *temp;
 temp=(struct node *)malloc(sizeof(struct node));
 printf("\n Enter students details:");
 printf("\n\nEnter Student's roll no:");
 scanf("%d",&temp->s_roll_no);
 printf("\n Enter student's grade:");
 fflush(stdin);
 scanf("%c",&temp->s_grade);
 printf("\n Enter student's name:");
 fflush(stdin);
 scanf("%s",&temp->s_name);
 temp->link=NULL;
 if(front==NULL)
 {
  front=temp;
  rear=temp;
 }
 else
 {
  rear->link=temp;
  rear=temp;
 }
}
void del()
{
 struct node *temp;
 if(front==NULL)
 {
  printf("\n QUEUE UNDERFLOW!");
  return;
 }
 else if(front==rear)
 {
  front=NULL;
  rear=NULL;
 }
 else
 {
  temp=front;
  front=front->link;
 }
 free(temp);
}
void display()
{
 struct node *temp;
 temp=front;
 if(temp==NULL)
 {
  printf("\n Queue empty!");
  return;
 }
 else
 {
  printf("\n Student's deatils:");
  while(temp!=NULL)
  {
   printf("\n Student's roll no:%d",temp->s_roll_no);
   printf("\n Student's grade:%c",temp->s_grade);
   printf("\n Student's name:%s",temp->s_name);
   temp=temp->link;
  }
 }
}