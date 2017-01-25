/*
   Name:Pooja Pathak
   Program no:11
   Program Name:WACP to insert a node in a doubly linked list, from left to right so
		that nodes of that doubly linked list will be in ascending order(use
		double pointer).
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<alloc.h>
struct node
{
 int data;
 struct node *left,*right;
};
void insert(struct node **);
void quit();
void display(struct node *);
int main()
{
 struct node *start=NULL;
 char ch;
 clrscr();
 while(1)
 {
  printf("\n MENU");
  printf("\n 1.Insert: i");
  printf("\n 2.Quit: q");
  printf("\n Enter choice:");
  fflush(stdin);
  ch=getchar();
  switch(ch)
  {
   case 'i':
   case 'I': insert(&start);
	     display(start);
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
void insert(struct node **st)
{
 struct node *temp,*q1;
 temp=(struct node *)malloc(sizeof(struct node));
 printf("\n Enter data (integer)");
 scanf("%d",&temp->data);
 if(*st==NULL)
 {
  *st=temp;
  (*st)->left=NULL;
  (*st)->right=NULL;
 }
 else
 {
  q1=*st;
  while(q1->right!=NULL)
  {
      q1=q1->right;
  }
  temp->left=q1;
  q1->right=temp;
  temp->right=NULL;
 }
}
void display(struct node *st)
{
 struct node *temp;
 if(st==NULL)
 {
  printf("\n List empty!");
  return;
 }
 else
 {
  temp=st;
  printf("\n List:");
  while(temp!=NULL)
  {
   printf("%d ",temp->data);
   temp=temp->right;
  }
 }
}
void quit()
{
 exit(0);
}