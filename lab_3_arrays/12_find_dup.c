#include<stdio.h>

void insertionSort(int arr[], int n) {
}

int main(){

    int n;
    printf("Enter size of array : ");
    scanf("%d", &n);
    
    int arr[n];
    for(int i = 0; i < n; i++){
        printf("Enter element : ");
        scanf("%d", &arr[i]);
    }

    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }

    for(int i = 1; i <= sizeof(arr)/sizeof(arr[0]); i++){
        if(arr[i] == arr[i-1]){
            printf("duplicate value : %d", arr[i]);
        }
    }
return 0;
}