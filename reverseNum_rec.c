//This C program finds the reverse of a number using recursion
#include <stdio.h>
#include <math.h>

int revNum(int n, int len);

int main(){
    int n;
    printf("Enter number: ");
    scanf("%d", &n);
    int temp = n, len = 0;
    while (temp != 0){
        len++;
        temp = temp/10;
    }

    int y = revNum(n, len);

    printf("Reversed number: %d", y);

    return 0;
}

int revNum(int n, int len){
    if (len == 1){
        return n;
    }
    else{
        return (((n % 10) * pow(10 , len-1)) + revNum(n/10, --len));
    }
}