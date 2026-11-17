#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("Enter size of array : ");
    scanf("%d", &n);
    int *arr = malloc(n*sizeof(int));

    if(arr != NULL){
    printf("enter array elements : \n");
    for(int i = 0; i < n; i++){
        printf("Element %d : ", i);
        scanf("%d", &arr[i]);
    }

    int index;
    printf("Enter index to insert at : ");
    scanf("%d", &index);

    int number;
    printf("Enter number to insert : ");
    scanf("%d", &number);

    arr = realloc(arr, (n+1)*sizeof(int));
    n+=1;

    for(int i = n-1; i > index; i--){
        arr[i] = arr[i-1];
    }

    arr[index] = number;
    printf("new array : \n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    }
}