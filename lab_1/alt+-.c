#include <stdio.h>

int main(){
int n;
printf("enter no. of elements to input in array : ");
scanf("%d", &n);
int arr[n], temp ;
for(int i = 0; i < n; i++){
    printf("enter number %d : ", i+1);
    scanf("%d", &arr[i]);
}

for(int i = 1; i < n; i++){
    if(arr[i-1] < 0){
        if(arr[i] > 0){
            continue;
        }
        else{
            for(int j = i+1; j < n; j++){
                if(arr[j] > 0){
                    temp = arr[j];
                    arr[i] = arr[j];
                    arr[j] = temp;
                    break;
                }
            }
        }
    }
    else{
        if(arr[i] < 0){
            continue;
        }
        else{
            for(int j = i+1; j < n; j++){
                if(arr[j] < 0){
                    temp = arr[j];
                    arr[i] = arr[j];
                    arr[j] = temp;
                    break;
                }
            }
        }

    }
}

printf("output array : \n");
for(int i = 0; i < n; i++){
    printf("%d ", arr[i]);
}
}