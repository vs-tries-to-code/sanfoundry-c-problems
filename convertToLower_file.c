//This C Program converts the content of file to lowercase
#include <stdio.h>
void showFile(FILE *f);
void convertToLower(FILE *f);
int main(){
    FILE *f;
    f = fopen("text.txt", "r+");
    if (f == NULL){
        printf("File error\n");
        return 1;
    }
    
    printf("File contents\n");
    showFile(f);
    printf("\n");

    rewind(f);
    convertToLower(f);
    
    rewind(f);
    printf("After conversion\n");
    showFile(f);

    fclose(f);

    return 0;
}

void showFile(FILE *f){
    char c;
    while ((c = fgetc(f)) != EOF){
        printf("%c", c);
    }
    return;
}

void convertToLower(FILE *f){
    int c;
    char ch;
    while ((c = fgetc(f)) != EOF)
    {   
        if(c >= 65 && c <= 90){
            fseek(f, -1, SEEK_CUR);
            ch = (char)c;
            ch += 32;
            fputc((char)ch, f);
        }
    }
    
    return;
    
}