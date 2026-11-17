#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

int main()
{

    struct node *start = NULL, *ptr = NULL, *tmp;

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

    struct node *prev, *next;
    prev = NULL;
    ptr = start;

    while(ptr != NULL){
        next = ptr -> link;
        ptr -> link = prev;
        prev = ptr;
        ptr = next;
    }
    start = prev;

    printf("\nlist after reversing : \n");
    ptr = start;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }

}


