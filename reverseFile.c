//This C Program reverses the contents of a file and print it.
#include <stdio.h>
void revFile(FILE *src, FILE *dest, long c);
long countCh(FILE *f);
void showFile(FILE *f);

int main(){
    FILE *f;
    FILE *f1;
    f = fopen("text.txt", "r");
    f1 = fopen("new.txt", "w+");
    if (f == NULL || f1 == NULL){
        printf("File error\n");
        return 1;
    }
    showFile(f);
    printf("\n");
    
    rewind(f);
    long ch = countCh(f);
    
    
    revFile(f, f1, ch);

    rewind(f1);
    showFile(f1);

    fclose(f);
    fclose(f1);

    return 0;
} 

void showFile(FILE *f){
    int ch;
    while ((ch = fgetc(f)) != EOF)
    {
        printf("%c", ch);
    }
    return;
    
}

long countCh(FILE *f){
    long count=0;
    int ch;
    while ((ch = fgetc(f)) != EOF)
    {
        count++;
    }
    return count;
    
}

void revFile(FILE *src, FILE *dest, long c){
    int ch;
    for (long i = c-1; i >= 0; i--){
        //move the pointer 
        fseek(src, i, SEEK_SET);
        ch = fgetc(src); 
        fputc(ch, dest);
    }
    
}
