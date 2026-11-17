#include<stdio.h>

int main(){

    int n;
    printf("Enter size of array : ");
    scanf("%d", &n);
    
    int arr[n];
    for(int i = 0; i < n; i++){
        printf("Enter element : ");
        scanf("%d", &arr[i]);
    }
    int ans[n];

    int before = 1;
    for(int i = 0; i < n; i++){
        ans[i] = before;
        before *= arr[i];
    }
    
    printf("Array :\n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    int after = 1;
    for(int i = n - 1; i >= 0; i--){
        ans[i] *= after;
        after *= arr[i];
    }

    printf("Product of array except self :\n");
    for(int i = 0; i < n; i++){
        printf("%d ", ans[i]);
    }
    printf("\n");

return 0;
}