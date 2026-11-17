#include<stdio.h>
#include <stdlib.h>
void push(int arr[], int n, int *top){
    int x;
    printf("\nEnter element to push : ");
    scanf("%d", &x);

    if(*top <= n - 1){
        arr[*top] = x;
        (*top)++;
    }
    else{
        printf("Overflow.");
    }    
}

void pop(int arr[], int n, int *top){
    if(*top > 0){
        free(top);
        (*top)--;
    }
    else{
        printf("\nUnderflow.");
    }
}

int main(){


    int n;
    printf("Enter size of stack : ");
    scanf("%d", &n);

    int arr[n];
    int top = 0;
    int i = 0;
    while(1){
        printf("Enter :\n1 - push element\n2 - pop element\n3 - print stack\n4 - end program\n");
        scanf("%d", &i);

        switch(i){
            case 1:
                push(arr, n, &top);
                break;
            
            case(2):
                pop(arr, n , &top);
                break;

            case(3):
                printf("Stack : ");
                if(top != 0){
                    for(int i = 0; i < top; i++){
                        printf("%d ", arr[i]);
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