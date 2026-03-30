#include <stdio.h>
#include <strings.h>

void convertLower(char s[]){
   while (*s != '\0'){
    if (*s >= 'A' && *s <= 'Z'){
        *s = *s + 32;
    }
    s++;
   } 
}

int main(){
    char text[100];
    printf("Enter string: ");
    fgets(text, sizeof(text), stdin);
    convertLower(text);
    printf("Converted string: %s", text);

    return 0;
}