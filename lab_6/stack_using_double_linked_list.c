#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node* prev;
    int data;
    struct node* next;
};

void push(struct node **start, struct node** ptr){
    
    int x;
    printf("Enter element to push : ");
    scanf("%d", &x);
    struct node *tmp = (struct node*)malloc(sizeof(struct node));
        if(tmp == NULL){
        printf("Overflow.\n\n");
        return;
    }

    tmp -> data = x;
    tmp -> next = NULL;
    tmp -> prev = (*ptr);

    if((*ptr) == NULL){
        *start = tmp;
        (*ptr) = tmp;
    }

    else{
        (*ptr) -> next = tmp;
    }   
    *ptr = tmp; 
}

void pop(struct node **start, struct node *(*ptr)){

    if((*ptr) == NULL){
        printf("underflow.\n\n");
        return;
    }
    else if((*ptr) -> prev == NULL){
        free((*ptr));
        *ptr = NULL;
        *start = NULL;
    }
    else{
        (*ptr) = (*ptr) -> prev;
        free((*ptr) -> next);
        (*ptr) -> next = NULL;
    }
}

int main(){

    struct node *start, (*ptr);
    start = NULL;
    ptr = start;

    int i = 0;
    while(1){
        printf("Enter :\n1 - push element\n2 - pop element\n3 - print stack\n4 - end program\n");
        scanf("%d", &i);

        switch(i){
            case 1:
                push(&start, &ptr);
                break;
            
            case(2):
                pop(&start, &ptr);
                break;

            case(3):
                printf("Stack : ");
                if(start != NULL){
                    ptr = start;
                    while(ptr != NULL){
                        printf("%d ", ptr -> data);
                        ptr = ptr -> next;
                    }
                printf("\n");
                }
                else{
                    printf("Empty.\n");
                }
                break;

            case(4):
                return 0;
        }
    }
}