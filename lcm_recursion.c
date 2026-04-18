#include <stdio.h>

int lcm(int a, int b);

int main (){
    int a, b;
    printf("Enter number a: ");
    scanf("%d", &a);
    printf("Enter number b: ");
    scanf("%d", &b);
    int x = lcm(a, b);
    printf("lcm is : %d", x);
    return 0;
}

int lcm(int a, int b){
    static int common = 1;
    if( common % a == 0 && common % b == 0){
        return common;
    }

    common++;

    lcm(a, b);
}