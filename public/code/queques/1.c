// 1. IMPLEMENT THE OPERATIONS OF SIMPLE QUEUE IN AN INTEGER ARRAY (INSERT, DELETE, PEEK, ISEMPTY, ISFULL)
#include <stdio.h>
#define size 5
void insert(int *queue, int *front, int *rear, int value)
{
    if ((*front <= *rear) && (*rear != size))
    {
        queue[(*rear)++] = value;
    }
    else
    {
        printf("Queue Full\n");
    }
}
void delete(int *queue, int *front, int *rear)
{
    if ((*front < *rear) && (*front != size))
    {
        printf("%d\n", queue[(*front)++]);
    }
    else
    {
        printf("Queue Empty\n");
    }
}
void peek(int *queue, int *front, int *rear)
{
    if ((*front < *rear) && (*front != size))
    {
        printf("%d\n", queue[*front]);
    }
    else
    {
        printf("Queue Empty\n");
    }
}
void isEmpty(int *queue, int *front, int *rear)
{
    if ((*front < *rear) && (*front != size))
    {
        printf("Queue Not Empty\n");
    }
    else
    {
        printf("Queue Empty\n");
    }
}
void isFull(int *queue, int *front, int *rear)
{
    if ((*front <= *rear) && (*rear != size))
    {
        printf("Queue Not Full\n");
    }
    else
    {
        printf("Queue Full\n");
    }
}
int main()
{
    int queue[size];
    int value, front = 0, rear = 0, choice;
    while (1)
    {
        printf("\n1.INSERT\n2.DELETE\n3.PEEK\n4.ISEMPTY\n5.ISFULL\n6.EXIT\nENTER THE OPERATION: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("ENTER THE VALUE: ");
            scanf("%d", &value);
            insert(queue, &front, &rear, value);
            break;
        case 2:
            delete (queue, &front, &rear);
            break;
        case 3:
            peek(queue, &front, &rear);
            break;
        case 4:
            isEmpty(queue, &front, &rear);
            break;
        case 5:
            isFull(queue, &front, &rear);
            break;
        case 6:
            return 0;
        default:
            break;
        }
    }
}