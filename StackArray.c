#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define max 20
static char e[max];
static int top=-1;
void push(char x);
char toppop();
void display();
int isempty();
void makempty();
void pop();
void balpara();
void push(char x)
{
   if(top==max-1)
      printf("Stack overflow");
   else
   {
      top++;
      e[top]=x;
   }
}
char toppop()
{
   if(top==-1)
      printf("Underflow");
   else
   {
      return e[top];
      top--;
   }
}
int isempty()
{
   if(top==-1)
      return 1;
   else
      return 0;
}
void makempty()
{
   while(top!=-1)
   {
      pop();
   }
}
void display()
{
   int i;
   printf("Elements in a stack are\n");
   for(i=0;i<=top;i++)
      printf("%c\t",e[i]);
}
void pop()
{
   if(top==-1)
      printf("Underflow");
   else
      top--;
}
void balpara()
{
    char exp[max], temp;
    printf("Enter the expression: ");
    scanf(" %s", exp);

    int i = 0, len, flag = 0;
    len = strlen(exp);

    while (i < len)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
           push(exp[i]);
        else
        {
            if (exp[i] == ')')
                temp = '(';
            else if (exp[i] == ']')
                temp = '[';
            else if (exp[i] == '}')
                temp = '{';
            else
            {
                i++;
                continue;
            }

            char ch = toppop();
            if (temp != ch)
            {
                flag = 1;
                break;
            }
        }
        i++;
    }
    if (flag == 1 && top!=-1)
      printf("Not Balanced\n");
    else
      printf("Balanced\n");
}
int main()
{
   int check,choice;
   char c;
   printf("MENU\n1.Push\n2.Pop\n3.Top pop\n4.Display\n5.Isempty\n6.Makempty\n7.Balancing Paranthesis\n8.Exit");
   do
   {
      printf("\nEnter your choice:");
      scanf("%d",&choice);
      switch(choice)
      {
         case 1:
            printf("Enter the element to be push:");
            scanf(" %c",&c);
            push(c);
            break;
         case 2:
            pop();
            break;
         case 3:
            printf("Top element is %c",toppop());
            break;
         case 4:
            display();
            break;
         case 5:
            check=isempty();
            if(check==0)
               printf("Stack is not empty");
            else
               printf("Stack is empty");
            break;
         case 6:
            makempty();
            printf("Stack is emptied");
            break;
         case 7:
            balpara();
            break;
         case 8:
            break;
         default:
            printf("Invalid choice");
      }
   }while(choice!=8);
   return 0;
}
