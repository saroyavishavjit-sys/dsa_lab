#include<stdio.h>
#include<stdlib.h>

void removedup(int **arr, int *n, int freq[], int i, int ptr){  
    if(n == 0){
        printf("n = 0! error...");
        return;
    }
    if(i == *n){                                                
        (*arr) = (int*)realloc((*arr), sizeof((*arr)[0])*(ptr));      
        *n = ptr;
        ++freq[ptr-1];
        return ;
    }
    if((*arr)[i] == (*arr)[i - 1]){
        removedup(arr, n, freq, i + 1, ptr);
        ++freq[ptr - 1];
        return;
    }
    else{
        if(ptr == i){
            removedup(arr, n, freq, i + 1, ptr + 1);
            ++freq[ptr - 1];
            return;
        }
    (*arr)[ptr] = (*arr)[i];
    removedup(arr, n, freq, i + 1, ptr + 1);
    ++freq[ptr - 1];
    return;
    }
}

int main(){
    int n;
    printf("Enter size of array : ");
    scanf("%d", &n);

    int *arr = (int*)malloc(n*sizeof(int));
    
    for(int i = 0; i < n; i++){
        printf("Enter element : ");
        scanf("%d", &arr[i]);
    }
  
    int freq[10] = {0};
    removedup(&arr, &n, freq, 1, 1);

    printf("Array Elements and frequency:\n");
    for(int i = 0; i < n; i++){
        printf("%d : %d\n", arr[i], freq[i]);
    }
    printf("\n");

return 0;
}