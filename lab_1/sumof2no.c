#include<stdio.h>

int main(){

int n;
printf("enter no. of elements : ");
scanf("%d", &n);

int arr[n];
for(int i = 0; i < n; i++){
    printf("enter no : ");
    scanf("%d", &arr[i]);
}

int sum ;
printf("enter the no. (sum) : ");
scanf("%d", &sum);

int found = 0, temp;

for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
        if (arr[j] > arr[j + 1]) {
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
        }
    }
}


for(int i = 0; i < n; i++){
    if((arr[i] == arr[i-1] && i != 0)){
        continue;
    }
    for(int j = i + 1; j < n; j++){
        if(arr[i] + arr[j] == sum){
            found = 1;
            printf("\n%d %d ", arr[i], arr[j]);
            break;
        }
    }
}

if (found == 0){
    printf("No such pair.");
}

return 0;
}