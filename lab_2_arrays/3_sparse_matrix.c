#include<stdio.h>

int main(){
    
int x;
int y;
printf("Enter dimensions of sparse matrix : \nm : ");
scanf("%d", &x);
printf("n : ");
scanf("%d", &y);

int MX[x*y];
int MY[x*y];
int MV[x*y];
int temp;
int k = 0;

printf("Enter elements at - \n");
for(int i = 0; i < x; i++){
    for(int j = 0; j < y; j++){
        printf("(%d,%d) = ", i, j);
        scanf("%d", &temp);
        if(temp != 0){
            MX[k] = i;
            MY[k] = j;
            MV[k] = temp;
            k++;
        }
    }
}

printf("\nMatrix\n");
int value = 0;
for(int i = 0; i < x; i++){
    for(int j = 0; j < y; j++){
        value = 0;
        for(int k = 0; k < x*y; k++){
            if((MX[k] == i) && (MY[k] == j)){
                value = MV[k];
                break;
            }
        }
        printf("%d ", value);
    }
    printf("\n");
}

printf("Elements of sparse matrix :\n");
for(int i = 0; i < k; i++){
    printf("(%d,%d) = %d\n", MX[i], MY[i], MV[i]);
}

return 0;
}
// printf("Enter values of sparse matrix \n(in format : (abscissa),(ordinate)=(value))\ntype 'END' to end inputs\nEnter : ");
// for(int i = 0; scanf("%d,%d=%d", &MX[i], &MY[i], &MV[i]) == 3; i++){
//     printf("Enter : ");
// }

// int found;
// int ele;

// printf("Matrix : \n");

// for(int i = 0; i < x; i++){
//     for(int j = 0; j < y; j++){
//         found = 0;

//         for(int k = 0; k < x*y; k++){

//             if((MX[k] == i) && (MY[k] == j)){
//                 found = MV[k];
//                 break;
//             }    
//         }

//         printf("%d ", found);

//     }
//     printf("\n");
// }
