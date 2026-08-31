#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

int main(){

    struct node *start = NULL, *ptr = NULL, *tmp;

    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++){
        tmp = (struct node *)malloc(sizeof(struct node));

        printf("Data of node %d: ", i);
        scanf("%d", &tmp->data);

        tmp->link = NULL;

        if (start == NULL){
            start = tmp;
            ptr = tmp;
        }

        else{
            ptr->link = tmp;
            ptr = tmp;
        }
    }

    ptr = start;
    while(ptr->link->link != NULL){
        ptr = ptr->link;
    }
    free(ptr->link);
    ptr->link = NULL;


    printf("\nlist after deleting last node : \n");
    ptr = start;
    while (ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }

    return 0;
}