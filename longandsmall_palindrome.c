#include <stdio.h>
#include <string.h>
int checkPalindrome(char *s){
    char *r = s + strlen(s) -1;
    while (r>s){
        if(*r != *s){
            return 0;
        }
        s++; r--;
    }
    return 1;
}
int main(){
    char line[200];
    char word[50];
    char longest[50] = "";
    char smallest[50] = "";

    int i = 0, j = 0;
    int found = 0;

    printf("Enter a line: ");
    fgets(line, sizeof(line), stdin);
    while (line[i] != '\0'){
        if( line[i] != ' ' && line[i] != '\n' && line[i] != '\0'){
            word[j++] = line[i];
        }
        else{
            word[j] = '\0';
        }

        int x = checkPalindrome(word);
        
        if (x == 1){
            if (found == 0){
                strcpy(longest, word);
                strcpy(smallest, word);
                found = 1;
            }

            else{
                if (strlen(word) > strlen(longest)){
                    strcpy(longest, word);
                }

                if (strlen(word) < strlen(smallest)){
                    strcpy(smallest, word);
                }
            }
        }

        j=0;

        i++;

    }

    printf("Longest palindrome: %s\n", longest);
    printf("Smallest palindrome: %s\n", smallest);

    return 0;
}