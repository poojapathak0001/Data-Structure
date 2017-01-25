/*
   Name:Pooja Pathak
   Program no:5
   Program Name:WACP to sort an array using quick sort technique(input some strings)
*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void input(char [][20],int);
void output(char [][20],int);
void quick_sort(char [][20],int,int);
int main()
{
 char names[10][20];
 int m;
 clrscr();
 printf("\n Enter total no of names:");
 scanf("%d",&m);
 input(names,m);
 quick_sort(names,0,m);
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
void quick_sort(char p[][20],int l,int h)
{
 char temp[20],key;
 int low,high;
 low=l;
 high=h;
 strcpy(key,(p[(low+high)/2]));
 do
 {
  while(strcmp(key,p[low])>0)
   low++;
  while(strcmp(key,p[high])<0)
   high--;
  if(low<=high)
  {
   strcpy(temp,p[low]);
   strcpy(p[low++],p[high]);
   strcpy(p[high--],temp);
  }
 }while(low<=high);
 if(l<high)
  quick_sort(p,l,high);
 if(low<h)
  quick_sort(p,low,h);
}