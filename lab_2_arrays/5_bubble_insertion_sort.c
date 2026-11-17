#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void bubble_sort(int nums[], int n){
        int temp;
        for(int i = n-1; i > 0; i--){
            for(int j = 0; j < i; j++){
                if(nums[j] > nums[j+1]){
                    temp = nums[j];
                    nums[j] = nums[j+1];
                    nums[j+1] = temp;
                }
            }
        }
    }
    
void insertion_sort(int nums[], int n) {
    int temp;
    for(int i = 1; i < n; i++){
        for(int j = i; j > 0; j--){
            if(nums[j] < nums[j-1]){
                temp = nums[j];
                nums[j] = nums[j-1];
                nums[j-1] = temp;
            }
        }
    }
}


int main(){

    int n, ele, min;
    printf("no. of ele : ");
    scanf("%d", &n);

    int arr1[n];
    int arr2[n];

    for(int i = 0; i < n; i++) {
        ele = rand() % 1000 + 1;
        arr1[i] = ele;
        arr2[i] = ele;
    }
    clock_t start, end;

    printf("BUBBLE SORT - ");
    start = clock();
    bubble_sort(arr1, n);
    end = clock();
    printf("Time taken : %f\n", (double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    insertion_sort(arr2, n);
    end = clock();
    
    printf("INSERTION SORT - \n");
    printf("Time taken : %f\n", (double)(end - start) / CLOCKS_PER_SEC);



return 0;
}