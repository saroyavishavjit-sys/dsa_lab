#include <stdio.h>

int main(){

    int n;
    printf("Enter size of array : ");
    scanf("%d", &n);
    
    int arr[n];
    for(int i = 0; i < n; i++){
        printf("Enter element : ");
        scanf("%d", &arr[i]);
    }

    int left = 0;
    int right = n - 1;
    int lsum = 0;
    int rsum = 0;

    while(left < right){
        if(left == right - 2){
            printf("equilibrium index : %d", ++left);
            return 0;
        }
        else if(lsum <= rsum){
            lsum += arr[left];
            left++;
        }
        else{
            rsum += arr[right];
            right--;
        }
    }
    printf("No such index");

return 0;
}