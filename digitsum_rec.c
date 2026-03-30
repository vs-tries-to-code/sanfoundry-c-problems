//This C program finds the sum of digits of a number using recursion
#include <stdio.h>

int sumDigit(int n){
    if (n==0){
        return 0;
    }
    else{
        return n%10 + sumDigit(n/10);  
    }

}

int main(){
    int x;
    printf("Enter number: ");
    scanf("%d", &x);
    int y = sumDigit(x);
    printf("Sum of digits: %d", y);
    
    return 0;
}