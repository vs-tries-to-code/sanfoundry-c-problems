//check whether a string is palindrome or not
#include <stdio.h>
#include <string.h>
int isPalindrome(char str[], int end){
    char *e = str + end;
    while (str < e){
        if (*str != *e){
            return 0;
        }
        str++;
        e--;
    }
    return 1;
}

void caseToLow(char str[]){
    while (*str != '\0'){
        if (*str >= 'A' && *str <= 'Z'){
            *str = *str + 32;
        }
        str++;  
    }
}
int main(){
    char text[100];
    printf("Enter string\n");
    scanf("%s", text);
    int last = strlen(text)-1;
    caseToLow(text);
    int x = isPalindrome(text, last);
    if (x==0){
        printf("The word is not palindrome");
    }
    else{
        printf("The word is a palindrome");
    }   

    return 0;
}