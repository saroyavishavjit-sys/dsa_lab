#include<stdio.h>

int main(){
    
int n;  
printf("Enter size of array :");
scanf("%d", &n);

int arr[n];
for(int i = 0; i < n; i++){
    printf("Enter element : ");
    scanf("%d",&arr[i]);
}

int r;
printf("Enter number of times to r : ");
scanf("%d",&r);
r %= n;

int temp;
for(int left = 0, right = n-1; left < right; left++, right--){
    temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
}

for(int left = 0, right = r-1; left < right; left++, right--){
    temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
}

for(int left = r, right = n-1; left < right; left++, right--){
    temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
}

printf("New Array : \n");
for(int i = 0; i < n; i++){
    printf("%d ", arr[i]);
}

return 0;
}