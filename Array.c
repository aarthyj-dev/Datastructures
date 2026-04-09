#include<stdio.h>
#include<stdlib.h>
int a[20],n,i,j,ch;
void create();
void insert();
void delete();
void search();
void find();
void remodd();
void display();
void create()
{
   printf("Enter the array elements:");
   for(i=0;i<n;i++)
      scanf("%d",&a[i]);
}
void insert()
{
   int pos,x;
   printf("Enter a position where to insert:");
   scanf("%d",&pos);
   printf("Enter the element to be inserted:");
   scanf("%d",&x);
   for(i=n-1;i>=pos-1;i--)
      a[i+1]=a[i];
   a[pos-1]=x;
   n++;
   printf("The array elements after inserting an element %d in position %d\n",x,pos);
   for(i=0;i<n;i++)
      printf("%d\t",a[i]);
}
void delete()
{
   int pos;
   printf("Enter a position where the element to be deleted:");
   scanf("%d",&pos);
   if(pos>n)
      printf("POSITION EXCEEDS");
   else
      for(i=pos;i<n;i++)
         a[i-1]=a[i];
      n--;
   printf("The array elements after deleting an element in a position %d\n",pos);
   for(i=0;i<n;i++)
      printf("%d\t",a[i]);
}
void search()
{
   int key,flag=0;
   printf("Enter the element to be searched:");
   scanf("%d",&key);
   for(i=0;i<n;i++)
   {
      if(a[i]==key)
      {
         printf("Element %d is found in a position %d",key,i+1);
         flag=1;
         break;
      }
      else
         continue;
   }
   if(flag==0)
      printf("Element %d is not found in the position",key);
}
void find()
{
   int pos;
   printf("Enter the position:");
   scanf("%d",&pos);
   if (pos>n)
      printf("POSITION EXCEEDS");
   else
      printf("Element is %d",a[pos-1]);
}
void display()
{
   printf("The array elements are ");
   for(i=0;i<n;i++)
      printf("%d\t",a[i]);
}
void remodd()
{
   for(i=0;i<n;i++)
   {
      if(a[i]%2!=0)
      {
         for(j=i+1;j<n;j++)
            a[j-1]=a[j];
         n--;
      }
   }
   printf("The array elements after removing odd numbers are ");
   for(i=0;i<n;i++)
      printf("%d\t",a[i]);
}
int main()
{
   printf("Enter the number of elements:");
   scanf("%d",&n);
   create();
   printf("MENU\n1.Insert\n2.Delete\n3.Search\n4.Find\n5.Display\n6.Remove odd numbers\n7.Exit\n");
   do
   {
      printf("\nEnter your choice:");
      scanf("%d",&ch);
      switch(ch)
      {
         case 1:
            insert();
            break;
         case 2:
            delete();
            break;
         case 3:
            search();
            break;
         case 4:
            find();
            break;
         case 5:
            display();
            break;
         case 6:
            remodd();
            break;
         case 7:
            break;
         default:
            printf("\nINVALID CHOICE");
            break;
     }
   }while(ch!=7);
   return 0;
}
