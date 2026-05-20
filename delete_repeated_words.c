#include <stdio.h>
#include <string.h>
void removeDup(char s[][50], int wordCount){
  int j = 0;
  for (int i=0; i< wordCount; i++){
    for (int l = 0; l< wordCount; l++){
        if (s[l][j] == '\0' || l == i)
        {
            continue;
        }

        if (strcmp(s[l], s[i]) == 0)
        {
            s[l][j] = '\0';
        }
        
    }
  }  
}
int main(){
    char text[100]; char twoD[10][50];
    printf("Enter string\n");
    fgets(text, sizeof(text), stdin);
    int j=0, k=0;
    for (int i=0; text[i] != '\0'; i++){
        if (text[i] == ' '){
            twoD[k][j] = '\0';
            k++;
            j=0;
        }

        else{
            twoD[k][j] = text[i];
            j++;
        }
    }

    twoD[k][j] = '\0';
    removeDup(twoD, k);          
    
    
}