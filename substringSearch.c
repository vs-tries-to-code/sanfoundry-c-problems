//This C Program checks the substring is present in the given string.
#include <stdio.h>
#include <string.h>
int main(){
    char str[100];
    char substr[30];
    printf("Enter string\n");
    fgets(str, sizeof(str), stdin);

    printf("Enter substring to search\n");
    fgets(substr, sizeof(substr), stdin);

    char *s1 = str;
    char *s2 = substr;
    int flag = 0;
    
    while (*s1 != '\0'){
        if (*s1 == *s2){
            flag = 1;
            break;
        }
        s1++;
    }
    if (flag == 0){
       printf("Substring not present in string\n"); 
    }
    else{
          int found = 1;
          while (*s1 != '\0' && *s2 != '\0'){
            if(*s1 != *s2){
                found = 0;
                break;
            }
            s1++; s2++;
            
          }

          if (found == 1){
            printf("Substring is in the string\n");
          }
    }

    return 0;
  
}