#include<stdio.h>


int main(){

    int n;
    printf("Enter no. of days : ");
    scanf("%d", &n);
    
    int stocks[n];
    for(int i = 0; i < n; i++){
        printf("Enter price of day %d : ", i + 1);
        scanf("%d", &stocks[i]);
    }

    int min_index = 0;
    int min = 0;
    int max_index = 0;
    int max_profit = 0;
    int profit = 0;
    for(int i = 0; i < n; i++){
        profit = stocks[i] - stocks[min];
        if(profit > max_profit){
            min_index = min;
            max_index = i;
            max_profit = profit;
        }

        if(stocks[i] < stocks[min_index]){
            min = i;
        }
    }
    printf("Buy on day : %d\nSell on day : %d\nProfit : %d", min_index + 1, max_index + 1, max_profit);
}