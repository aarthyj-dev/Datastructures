#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct employee
{
   int id,ex;
   char name[20];
};
struct employee e[50];
int n,i,ch,j;
void insert();
void delete();
void search();
void retrieve();
void display();
int compare(char s1[20],char s2[20]);
void insert()
{
   int pos,nid,nex;
   char nname[20];
   printf("\nEnter the position to where to be inserted:");
   scanf("%d",&pos);
   printf("\nEnter the id:");
   scanf("%d",&nid);
   printf("\nEnter the name:");
   scanf("%s",nname);
   printf("\nEnter the years of experience:");
   scanf("%d",&nex);
   for(i=n-1;i>=pos-1;i--)
      e[i+1]=e[i];
   e[pos-1].id=nid;
   strcpy(e[pos-1].name,nname);
   e[pos-1].ex=nex;
   n++;
   printf("After inserting, the details are\n");
   display();
}
void delete()
{
   int pos;
   printf("Enter the position where the element to be deleted:");
   scanf("%d",&pos);
   for(i=pos;i<n;i++)
      e[i-1]=e[i];
   n--;
   printf("After deleting,the details are\n");
   display();
}
void search()
{
   int x,flag=0;
   printf("Enter the id to be searched:");
   scanf("%d",&x);
   for(i=0;i<n;i++)
   {
      if(e[i].id==x)
      {
         printf("ID %d is found at position %d",x,i+1);
         flag=1;
         break;
      }
      else
         continue;
   }
   if (flag==0)
      printf("ID is not found");
}
void retrieve()
{
   char key[20];
   int check,flag=0;
   printf("Enter the name:");
   scanf("%s",key);
   for(i=0;i<n;i++)
   {
      check=compare(e[i].name,key);
      if (check==0)
         continue;
      else
      {
         flag=1;
         printf("\nDetails of the employee name %s",key);
         printf("\n\tID:%d",e[i].id);
         printf("\n\tNAME:%s",e[i].name);
         printf("\n\tEXPERIENCE:%d",e[i].ex);
         break;
      }
   }
   if (flag==0)
      printf("\nNo data found with name %s",key);
}
void display()
{
   for(i=0;i<n;i++)
   {
       printf("\nDetails of the employee %d",i+1);
       printf("\n\tID:%d",e[i].id);
       printf("\n\tNAME:%s",e[i].name);
       printf("\n\tEXPERIENCE:%d",e[i].ex);
   }
}
void sort()
{
   struct employee temp;
   for(i=0;i<n;i++)
   {
      for(j=i+1;j<n;j++)
      {
         if(e[i].ex>e[j].ex)
         {
            temp=e[i];
            e[i]=e[j];
            e[j]=temp;
         }
      }
   }
   printf("\nAfter sorting the details based on years of experience");
   display();
}
int compare(char s1[20],char s2[20])
{
   int count=0,i=0;
   while (s1[i]!='\0' && s2[i]!='\0')
   {
      if(s1[i]!=s2[i])
      {
         count++;
         break;
      }
      i++;
   }
   if(count==0)
      return 1;
   else
      return 0;
}
int main()
{
   printf("Enter the number of employees:");
   scanf("%d",&n);
   printf("Enter the details:");
   for(i=0;i<n;i++)
   {
      printf("Enter the details of the employee %d",i+1);
      printf("\nEnter the id:");
      scanf("%d",&e[i].id);
      printf("\nEnter the name:");
      scanf("%s",e[i].name);
      printf("\nEnter the experience:");
      scanf("%d",&e[i].ex);
   }
   printf("MENU\n1.Insert\n2.Delete\n3.Search\n4.Retrieve\n5.Display\n6.Sort\n7.Exit");
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
            retrieve();
            break;
         case 5:
            display();
            break;
         case 6:
            sort();
            break;
         case 7:
            break;
         default:
            printf("\nINVALID CHOICE choose b/w-->(1-->7)");
      }
   }while(ch!=7);
   return 0;
}
