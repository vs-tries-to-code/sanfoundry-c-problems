//This C program, using recursion, finds the binary equivalent of a decimal number entered by the user.
#include <stdio.h>

int toBinary(int x);

int main(){
    int n;
    printf("Enter positive integer to convert to binary: ");
    scanf("%d", &n);
    int y = toBinary(n);

    printf("Binary equivalent: %d", y);

    return 0;
}

int toBinary(int x){
    if (x == 0){
        return 0;

    }

    else{
        return ((x % 2) + 10 * toBinary(x/2));
    }
}