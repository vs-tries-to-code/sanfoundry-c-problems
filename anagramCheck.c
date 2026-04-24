//Two strings are said to be anagrams if they satisfy two conditions, the length of both strings must be equal to each other and second the strings must have the same set of characters.
#include <stdio.h>
#include <string.h>
void sortWord(char s[], int len);
int wordCompare(char s1[], char s2[]);
int lengthStr(char s[]);
int main(){
    char word1[50];
    char word2[50];
    printf("Enter string\n");
    scanf("%s", word1);
    printf("Enter string\n");
    scanf("%s", word2);
    int len1 = lengthStr(word1);
    int len2 = lengthStr(word2);
    if (len1 != len2){
        printf("The words are not anagrams\n");
        return 0;
    }

    sortWord(word1, len1);
    sortWord(word2, len2);

    int cmp = wordCompare(word1, word2);
    if (cmp == 0){
        printf("The words are anagrams\n");
    }
    else{
        printf("The words are not anagrams\n");
    }

    return 0;

    
}

void sortWord(char s[], int n){
    for(int i=0; s[i] != '\0'; i++){
        for(int j=0; j = n-i-1; j++){
            if (s[j] > s[j+1]){
                char temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }
}

int wordCompare(char s1[], char s2[]){
    while (*s1 != '\0' && *s2 != '\0'){
        if (*s1 != *s2){
            return 1;
        }
        s1++; s2++;
    }
    if (*s1 == '\0' && *s2 == '\0'){
        return 0;
    }
}

int lengthStr(char s[]){
    int len=0;
    while (*s != '\0'){
        len++;
        s++;
    }
    return len;
}

