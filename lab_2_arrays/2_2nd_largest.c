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

int l1, l2, s1, s2;

if(arr[0] >= arr[1]){
    l1 = arr[0];
    l2 = arr[1];
    s1 = arr[1];
    s2 = arr[0];

}
else{
    l1 = arr[1];
    l2 = arr[0];
    s1 = arr[0];
    s2 = arr[1];


}

for(int i = 2; i < n; i++){
    if(arr[i] >= l1){
        l2 = l1;
        l1 = arr[i];
    }
    if(arr[i] <= s1){
        s2 = s1;
        s1 = arr[i];
    }
}
printf("Second largest number is : %d\n", l2);
printf("Second smallest number is : %d", s2);


return 0;
}