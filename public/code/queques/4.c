// 4. IMPLEMENT THE OPERATIONS OF QUEUE DYNAMICALLY OF STRING (INSERT, DELETE, PEEK, ISEMPTY, ISFULL)
#include <stdio.h>
#include <stdlib.h>
struct node
{
    char data;
    struct node *next;
};
int isFull()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        free(temp);
        return 1;
    }
    free(temp);
    return 0;
}
int isEmpty(struct node *start)
{
    if (start->next == NULL)
        return 1;
    return 0;
}
int insert(struct node *start, struct node *end, char val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp != NULL)
    {
        temp->next = NULL;
        temp->data = val;
        if (end->next != NULL)
        {
            end->next->next = temp;
        }
        end->next = temp;
        if (start->next == NULL)
        {
            start->next = temp;
        }
        return 1;
    }
    return 0;
}
void delete(struct node *start)
{
    if (start->next != NULL)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        printf("%c", start->next->data);
        temp = start->next;
        start->next = start->next->next;
        free(temp);
    }
    else
    {
        printf("QUEUE EMPTY");
    }
}
void peek(struct node *start)
{
    if (start->next != NULL)
    {
        printf("%c", start->next->data);
    }
    else
    {
        printf("QUEUE EMPTY");
    }
}
int main()
{
    struct node *start = (struct node *)malloc(sizeof(struct node));
    struct node *end = (struct node *)malloc(sizeof(struct node));
    start->next = NULL;
    end->next = NULL;
    int val, choice;
    while (1)
    {
        printf("\n1.INSERT\n2.DELETE\n3.PEEK\n4.ISEMPTY\n5.ISFULL\n6.EXIT\nENTER THE OPERATION: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("ENTER THE VALUE: ");
            scanf(" %c", &val);
            if (!insert(start, end, val))
                printf("QUEUE IS FULL");
            break;
        case 2:
            delete (start);
            break;
        case 3:
            peek(start);
            break;
        case 4:
            printf(isEmpty(start) ? "QUEUE IS EMPTY" : "QUEUE IS NOT EMPTY");
            break;
        case 5:
            printf(isFull(start) ? "QUEUE IS FULL" : "QUEUE IS NOT FULL");
            break;
        case 6:
            return 0;
        default:
            break;
        }
    }
    return 0;
}
