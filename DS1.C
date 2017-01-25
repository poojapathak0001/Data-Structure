/*
   Name:Pooja Pathak
   Program no:1
   Program Name:WACP to store N elements in an array,and then check
		how many elements are palindrome number in that array.
*/
#include<stdio.h>
#include<process.h>
#include<conio.h>
void check_pal(int *,int);
void input(int *,int);
void output(int *,int);
int main()
{
  int arr[20],N;
  clrscr();
  printf("\n Enter the length of array(max 20):");
  scanf("%d",&N);
  if(N<=20)
  {
    input(arr,N);
    output(arr,N);
    check_pal(arr,N);
  }
  else
  {
   printf("\n Max. size exceeded!");
   exit(0);
  }
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
void check_pal(int *p,int l)
{
 int i,c=0,r,a=0,s;
 for(i=0;i<l;i++)
 {
  a=p[i];s=0;
  while(a!=0)
  {
   r=a%10;
   s=s*10+r;
   a=a/10;
  }
  if(s==p[i])
  {
   c++;
   printf("\n Element %d is palindrome no.",p[i]);
  }
 else
  printf("\n Element %d is not a palindrome no.",p[i]);
 }
 printf("\n Total no of palindrome no.s in array is %d.",c);
}
