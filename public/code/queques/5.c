// 5. IMPLEMENT THE OPERATIONS OF CIRCULAR QUEUE IN AN INTEGER ARRAY (INSERT, DELETE, PEEK, ISEMPTY, ISFULL)
#include <stdio.h>
#define size 5
int isFull(int *queue, int *front, int *rear)
{
    if (*rear - *front < size)
        return 0;
    else
        return 1;
}
int isEmpty(int *queue, int *front, int *rear)
{
    if (*front < *rear)
        return 0;
    else
        return 1;
}
void insert(int *queue, int *front, int *rear, int val)
{

    if (!isFull(queue, front, rear))
    {
        queue[((*rear)++) % size] = val;
    }
    else
    {
        printf("QUEUE FULL\n");
    }
}
void delete(int *queue, int *front, int *rear)
{
    if (!(isEmpty(queue, front, rear)))
    {
        printf("%d\n", queue[((*front)++) % size]);
    }
    else
    {
        printf("QUEUE EMPTY\n");
    }
}
void peek(int *queue, int *front, int *rear)
{
    if (!(isEmpty(queue, front, rear)))
    {
        printf("%d\n", queue[(*front) % size]);
    }
    else
    {
        printf("QUEUE EMPTY\n");
    }
}

int main()
{
    int queue[size];
    int val, choice = 4, front = 0, rear = 0;
    while (1)
    {
        printf("1.INSERT\n2.DELETE\n3.PEEK\n4.ISEMPTY\n5.ISFULL\n6.EXIT\nENTER CHOICE : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("ENTER NUMBER : ");
            scanf("%d", &val);
            insert(queue, &front, &rear, val);
            break;
        case 2:
            delete (queue, &front, &rear);
            break;
        case 3:
            peek(queue, &front, &rear);
            break;
        case 4:
            printf("%s", isEmpty(queue, &front, &rear) ? "QUEUE IS EMPTY\n" : "QUEUE IS NOT EMPTY\n");
            break;
        case 5:
            printf("%s", isFull(queue, &front, &rear) ? "QUEUE IS FULL\n" : "QUEUE IS NOT FULL\n");
            break;
        case 6:
            return 0;
        default:
            break;
        }
    }

    return 1;
}