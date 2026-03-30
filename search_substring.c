#include <stdio.h>
#include <string.h>
int findSubstring(char s[], char target[], int len_s, int len_target){
    int flag = 0;
    while (s <= len_s - len_target){
        if (*s != *target){
            flag=1;
        }

    }
}
int main(){
    char str[100];
    char target[100];
    printf("Enter string: \n");
    scanf("%s", str);

    printf("Enter target substring:\n");
    scanf("%s", target);

    int x = findSubstring(str, target, strlen(str)-1, strlen(target)-1);
    if (x){
        printf("Substring found\n");
    }
    else{
        printf("Substring not found\n");
    }
}