#include <stdio.h>
#include <stdlib.h>
#define max 10
static int rear = -1, front = 0, Q[max];
void enqueue();
void dequeue();
void search();
void retrieve();
void isempty();
void makempty();
void display();
void enqueue()
{
    int x;
    if (rear == max - 1)
        printf("Queue is overflow\n");
    else
    {
        printf("Enter the element to be inserted: ");
        scanf("%d", &x);
        rear++;
        Q[rear] = x;
    }
}
void dequeue()
{
    if (front > rear)
        printf("Queue is underflow\n");
    else
        front++;
}
void search()
{
    int key, i, found = 0;
    printf("Enter the element to be searched: ");
    scanf("%d", &key);
    if (front > rear)
        printf("Queue is Empty\n");
    else
    {
        for (i = front; i <= rear; i++)
        {
            if (Q[i] == key)
            {
                found = 1;
                break;
            }
        }
        if (found)
            printf("Element is Found\n");
        else
            printf("Element is not found\n");
    }
}
void retrieve()
{
    int pos;
    printf("Enter a position (1-based): ");
    scanf("%d", &pos);
    if (pos < 1 || pos > (rear - front + 1))
        printf("Position exceeds bounds\n");
    else
        printf("Element at position %d is: %d\n", pos, Q[front + pos - 1]);
}
void isempty()
{
    if (front > rear)
        printf("Queue is Empty\n");
    else
        printf("Queue is not Empty\n");
}
void makempty()
{
    while (front <= rear)
        dequeue();
    printf("Queue is emptied\n");
}
void display()
{
    int i;
    if (front > rear)
        printf("Queue is Empty\n");
    else
    {
        printf("Queue elements are: ");
        for (i = front; i <= rear; i++)
            printf("%d ", Q[i]);
        printf("\n");
    }
}
int main()
{
    int choice;
    printf("MENU\n1.Enqueue\n2.Dequeue\n3.Search\n4.Retrieve\n5.Isempty\n6.Makempty\n7.Display\n8.Exit\n");
    do
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                search();
                break;
            case 4:
                retrieve();
                break;
            case 5:
                isempty();
                break;
            case 6:
                makempty();
                break;
            case 7:
                display();
                break;
            case 8:
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 8);
    return 0;
}
