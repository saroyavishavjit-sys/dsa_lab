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

    int maxl = 1;
    int cont = 1;
    for(int i = 1; i < n; i++){
        if(arr[i] - arr[i - 1] == 1){
            cont ++;
            if(cont > maxl){
                maxl = cont;
            }
        }
        else{
            cont = 1;
        }
        
    }
    printf("\nMax no. of consecutive sequence of integers : %d", maxl);

return 0;
}