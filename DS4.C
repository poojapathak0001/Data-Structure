/*
   Name:Pooja Pathak
   Program no:4
   Program Name:WACP to sort an array using insertion sort technique(input some strings)
*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void input(char [][20],int);
void output(char [][20],int);
void ins_sort(char [][20],int);
int main()
{
 char names[10][20];
 int m;
 clrscr();
 printf("\n Enter total no of names:");
 scanf("%d",&m);
 input(names,m);
 ins_sort(names,m);
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
void ins_sort(char p[][20],int m)
{
 int i,j=0;char temp[20];
 for(i=1;i<=m;i++)
 {
  strcpy(temp,p[i]);
  j=i-1;
  while((strcmp(temp,p[j])<0) && (j>=0))
  {
   strcpy(p[j+1],p[j]);
   j=j-1;
  }
    strcpy(p[j+1],temp);
}
}
