#include<stdio.h>
#include<stdlib.h>

int main(){
    
int n;
printf("Enter size of array : ");
scanf("%d", &n);

int *arr = malloc(n*sizeof(int));
if (arr == NULL) {
    printf("Memory allocation failed!\n");
    return 1;
}

for(int i = 0; i < n; i++){
    printf("Enter element %d : ", i);
    scanf("%d", &arr[i]);  
    }

int ind;
printf("Enter index to delete : ");
scanf("%d", &ind);

for(int i = ind; i < n-1; i++){
    arr[i] = arr[i+1];
}
n = n-1;

arr = realloc(arr, n*sizeof(int));

printf("New Array : \n");
for(int i = 0; i < n; i++){
    printf("%d ", arr[i]);
}


return 0;
}