#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};

int main(){
    struct node *ptr = NULL, *start = NULL, *ptr1;
    int n;
    printf("Enter number of nodes in circular linked list : ");
    scanf("%d", &n);

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

    //deletion
    int position;
    printf("\ndelete node at position :");
    scanf("%d", &position);

    if(n < position){
        printf("Invalid position.");
        return 1;
    }
    else if(n == 1 ){
        free(start);
        start == NULL;
    }
    else{
        ptr = start;
        if(position == 1){
            ptr1 = start;
            start = start -> link;
            free(ptr1);
        }
        for(int i = 1; i < position - 1; i++){
            ptr = ptr -> link;
        }
        ptr1 = ptr -> link;
        ptr -> link = ptr1 -> link;
        free(ptr1);
    }


    // print list

    printf("\nList after deleting last node : \n");
    if(n == 1){
        printf("Empty.");
    }
    else{
        printf("\nnode address : node data : node link\n");

        ptr = start;
        do{
            printf("%u : %d : %u\n", ptr, ptr -> data, ptr -> link);
            ptr = ptr -> link;
        }while(ptr != start);
    }

return 0;
}