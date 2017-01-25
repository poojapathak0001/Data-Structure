/*
   Name:Pooja Pathak
   Program no:2
   Program Name:WACP to sort merge two sorted arrays into third array.
*/
#include<stdio.h>
#include<process.h>
#include<conio.h>
void input(int *,int);
void output(int *,int);
void sort(int *,int);
void merge(int *,int *,int *,int,int);
int main()
{
 int arr1[10],arr2[10],arr3[20],m,n;
 clrscr();
 printf("\nEnter the length of first array(max 10):");
 scanf("%d",&m);
 if(m<=10)
  {
    input(arr1,m);
    sort(arr1,m);
    output(arr1,m);
  }
  else
  {
   printf("\n Max. size exceeded!");
   exit(0);
  }
 printf("\n Enter the length of second array(max 10):");
 scanf("%d",&n);
 if(n<=10)
  {
    input(arr2,n);
    sort(arr2,n);
    output(arr2,n);
  }
  else
  {
   printf("\n Max. size exceeded!");
   exit(0);
  }
  merge(arr1,arr2,arr3,m,n);
  printf("\n\n After merging:");
  output(arr3,(m+n));
  getch();
  return 0;
}
void input(int *p,int l)
{
 int i;
 printf("\n Enter the elements:");
 for(i=0;i<l;i++)
 scanf("%d",(p+i));
}
void output(int *p,int l)
{
 int i;
 printf("\n Array is:");
 for(i=0;i<l;i++)
 printf("%d ",*(p+i));
}
void sort(int *p,int l)
{
 int i,j,temp;
 for(i=0;i<l;i++)
 {
  for(j=i;j<l;j++)
   {
    if(p[i]>p[j+1])
     {
      temp=p[j+1];
      p[j+1]=p[i];
      p[i]=temp;
     }
   }
 }
}
void merge(int *p,int *q,int *r,int m,int n)
{
 int i=0,j=0,k=0;
 while(i<m && j<n)
 {
  if(p[i]<q[j])
   {
    r[k]=p[i];
    i++;
   }
  else
   {
    r[k]=q[j];
    j++;
   }
   k++;
 }
 if(i==m)
  {
   while(j<n)
   {
    r[k]=q[j];
    k++;
    j++;
   }
  }
 else if(j==n)
  {
   while(i<m)
   {
    r[k]=p[i];
    i++;k++;
   }
  }
}
