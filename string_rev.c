//Reversing a string (two pointer approach  )

#include <stdio.h>
#include <string.h>
int main(){
    char text[100];
    printf("Enter string\n");
    scanf("%s", text);
    char *p = text;
    char *e = text + strlen(text)-1;
    while (p < e){
        char temp = *p;
        *p = *e;
        *e = temp;
        p++;
        e--;
    }

    printf("Reversed string: %s", text);

    return 0;

    
}