/*
   Name:Pooja Pathak
   Program no:7
   Program Name:WACP to push and pop elements from the stack using linked list,each node should
		have the following information about employee emp_id,emp_name(single word name)
		,emp_salary.(use local pointer i.e. with return statement).
*/
#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<stdlib.h>
struct node
{
 int emp_id;
 int emp_sal;
 char emp_name[20];
 struct node *link;
};
void push(struct node **);
void pop(struct node **);
void display(struct node *);
int main()
{
 struct node *top=NULL;
 char ch;
 while(1)
  {
   printf("\n MENU");
   printf("\n 1.push: p");
   printf("\n 2.pop: d");
   printf("\n 3. quit: q");
   printf("\n Enter choice:");
   fflush(stdin);
   ch=getchar();
   switch(ch)
   {
    case 'p':
    case 'P': push(&top);
	      display(top);
	      break;
    case 'd':
    case 'D': pop(&top);
	      display(top);
	      break;
    case 'q':
    case 'Q': exit(0);
	      break;
    default: printf("\n Invalid choice");
	      break;
   }
 }
 getch();
 return 0;
}
void push(struct node **t)
{
 struct node *temp;
 temp=(struct node *)malloc(sizeof(struct node));
 printf("\n Enter employee id:");
 scanf("%d",&temp->emp_id);
 printf("\n Enter employee salary:");
 scanf("%d",&temp->emp_sal);
 printf("\n Enter employee name:");
 fflush(stdin);
 scanf("%s",&temp->emp_name);
  if(*t==NULL)
 {
  *t=temp;
  (*t)->link=NULL;
 }
 else
 {
  temp->link=*t;
  *t=temp;
 }
}
void pop(struct node **t)
{
 struct node *temp;
 if((*t)==NULL)
 {
  printf("\n NO ELEMENT!");
  return;
 }
 else
 {
  temp=*t;
  *t=(*t)->link;
 }
 free(temp);
}
void display(struct node *t)
{
 struct node *tmp;
 if(t==NULL)
 {
  printf("\n List Empty!");
  return;
 }
 else
 {
  tmp=t;
  printf("\n Details:");
  while(tmp!=NULL)
  {
   printf("\n Emp id:%d",tmp->emp_id);
   printf("\n Emp salary:%d",tmp->emp_sal);
   printf("\n Emp name:%s",tmp->emp_name);
   tmp=tmp->link;
  }
 }
}