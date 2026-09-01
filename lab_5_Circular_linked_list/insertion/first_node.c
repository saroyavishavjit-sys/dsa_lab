#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};

int main(){
    struct node *ptr = NULL, *start = NULL;
    int n;
    printf("Enter number of nodes in circular linked list : ");
    scanf("%d", &n);

    if(n <= 0){
        printf("Invalid.");
        return 1;
    }

    int data;
    for(int i = 1; i <= n; i++){
        printf("Enter data of node %d : ", i);
        scanf("%d", &data);

        struct node *tmp = (struct node*)malloc(sizeof(struct node));

        tmp->data = data;
        tmp->link = NULL;

        if(i == 1){
            start = tmp;
            ptr = tmp;                        
        }
        else{
            ptr->link = tmp;
            ptr = tmp;
        }
    }
    ptr->link = start;

    
    //print list
    printf("List :\n\nnode address : node data : node link\n");
    ptr = start;
    do{
        printf("%u : %d : %u\n", ptr, ptr -> data, ptr -> link);
        ptr = ptr -> link;
    }while(ptr != start);
    
    //insert node

    printf("\nEnter data of node to be inserted : ");
    scanf("%d", &data);

    struct node *tmp = (struct node*)malloc(sizeof(struct node));

    tmp->data = data;
    tmp->link = start;

    ptr = start;
    do{
        ptr = ptr -> link;
    }while(ptr -> link != start);

    ptr -> link = tmp;

    start = tmp;

    // print list
    printf("List :\n\nnode address : node data : node link\n");

    ptr = start;
    do{
        printf("%u : %d : %u\n", ptr, ptr -> data, ptr -> link);
        ptr = ptr -> link;
    }while(ptr != start);

return 0;
}