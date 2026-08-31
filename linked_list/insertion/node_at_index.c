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

    int position;
    int data;
    printf("\ninsert node at position :");
    scanf("%d", &position);
    tmp = (struct node*)malloc(sizeof(struct node)); 
    printf("data of node : ");
    scanf("%d", &data);

    tmp->data = data;
    tmp->link = NULL;
    ptr = start;
    for(int i = 1; i < position - 1; i++){
        ptr = ptr-> link;
    }
    tmp->link = ptr->link;
    ptr->link = tmp;


    printf("\nlist after inserting at position %d node : \n", position);
    ptr = start;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }

    return 0;
}