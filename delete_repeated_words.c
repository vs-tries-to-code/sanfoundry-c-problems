#include <stdio.h>
#include <string.h>
void removeDup(char s[][]){
    
}
int main(){
    char text[100]; char twoD[10][50];
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
    
    removeDup(twoD);
    
}