#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int jobid;
    char name[20];
    struct node *next;
};
typedef struct node *queue;
static queue rear = NULL;
static queue front = NULL;
void enqueuejob();
void dequeuejob();
int isnojob(queue front);
void emptyjobs();
void displayjobs();
void enqueuejob()
{
    queue temp = (queue)malloc(sizeof(struct node));
    if (!temp)
    {
        printf("Memory allocation failed\n");
        return;
    }
    int id;
    char n[20];
    printf("Enter job id: ");
    scanf("%d", &id);
    printf("Enter the job name: ");
    scanf("%s", n);
    temp->jobid = id;
    strcpy(temp->name, n);
    temp->next = NULL;
    if (rear == NULL)
        front = temp;
    else
        rear->next = temp;
    rear = temp;
}
void dequeuejob()
{
    if (!isnojob(front))
    {
        queue k = front;
        front = front->next;
        free(k);
    }
    else
        printf("No jobs to dequeue.\n");
}

int isnojob(queue front)
{
    return front == NULL;
}
void emptyjobs()
{
    while (!isnojob(front))
        dequeuejob();
}
void displayjobs()
{
    queue temp = front;
    if (isnojob(temp))
    {
        printf("No jobs in the queue.\n");
        return;
    }
    while (temp != NULL)
    {
        printf("Job ID: %d, Job Name: %s\n", temp->jobid, temp->name);
        temp = temp->next;
    }
}
int main()
{
    int ch;
    printf("\n MENU\n1.Enqueue job\n2.Dequeue job\n3.Is no job\n4.Empty jobs\n5.Display jobs\n6.Exit\n");
    do
    {
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                enqueuejob();
                break;
            case 2:
                dequeuejob();
                break;
            case 3:
                if (isnojob(front))
                    printf("There are jobs in the queue.\n");
                else
                    printf("No jobs in the queue.\n");
                break;
            case 4:
                emptyjobs();
                break;
            case 5:
                displayjobs();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (ch != 6);
    return 0;
}
/*OUTPUT
MENU
1.Enqueue job
2.Dequeue job
3.Is no job
4.Empty jobs
5.Display jobs
6.Exit
Enter your choice: 1
Enter job id: 100
Enter the job name: scan
Enter your choice: 1
Enter job id: 101
Enter the job name: print
Enter your choice: 1
Enter job id: 100
Enter the job name: scan
Enter your choice: 5
Job ID: 100, Job Name: scan
Job ID: 101, Job Name: print
Job ID: 100, Job Name: scan
Enter your choice: 2
Enter your choice: 5
Job ID: 101, Job Name: print
Job ID: 100, Job Name: scan
Enter your choice: 3
There are jobs in the queue.
Enter your choice: 4
Enter your choice: 5
No jobs in the queue.
Enter your choice: 6
Exiting...
*/
