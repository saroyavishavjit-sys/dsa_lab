#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

int main()
{

    struct node *start = NULL, *ptr = NULL, *tmp, *ptr1;

    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        tmp = (struct node *)malloc(sizeof(struct node));

        printf("Data of node %d: ", i);
        scanf("%d", &tmp->data);

        tmp->link = NULL;

        if (start == NULL)
        {
            start = tmp;
            ptr = tmp;
        }
        else
        {
            ptr->link = tmp;
            ptr = tmp;
        }
    }

    int index;
    printf("Enter number of the node to delete : ");
    scanf("%d", &index);

    ptr = start;
    if (index == 1)
    {
        ptr = start;
        start = start->link;
        free(ptr);
    }
    else
    {
        for (int i = 1; i < index - 1; i++)
        {
            ptr = ptr->link;
        }
        ptr1 = ptr->link;
        ptr->link = ptr->link->link;
        free(ptr1);
    }

    printf("\nlist after deleting %d node : \n", index);
    ptr = start;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }

    return 0;
}