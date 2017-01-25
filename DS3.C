/*
   Name:Pooja Pathak
   Program no:3
   Program Name:WACP to sort 10 names(strings) given by user,using bubble sort
		technique.
*/
#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include<conio.h>
void input(char [][20],int);
void output(char [][20],int);
void bsort(char [][20],int);
int main()
{
 char names[10][20];
 int m;
 clrscr();
 printf("\n Enter total no of names:");
 scanf("%d",&m);
 input(names,m);
 bsort(names,m);
 output(names,m);
 getch();
 return 0;
}
void input(char p[10][20],int m)
{
 int i,j=0;
 printf("\n Enter names:");
 for(i=0;i<=m;i++)
 {
  gets(p[j]);
  j++;
 }
}
void output(char p[10][20],int m)
{
 int i,j=0;
 printf("\n Names are:");
 for(i=0;i<=m;i++)
 {
  puts(p[j]);
  j++;
 }
}
void bsort(char c[10][20],int m)
{
 int i,j;char temp[20];
 for(i=0;i<=m;i++)
 {
   for(j=0;j<=m-1;j++)
   {
    if(strcmp(c[j],c[j+1])>0)
    {
     strcpy(temp,c[j]);
     strcpy(c[j],c[j+1]);
     strcpy(c[j+1],temp);
    }
   }
 }
}