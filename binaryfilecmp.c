//This C Program compares two binary files, printing the first byte position where they differ.
#include <stdio.h>

void binCompare(FILE *f1, FILE *f2){
    int c1, c2;
    int pos = 1;
    while (1){
        c1  = fgetc(f1);
        c2 = fgetc(f2);
        if (c1 == EOF && c2 == EOF){
            printf("File are equal\n");
            return;
        }
        if (c1 == EOF || c2 == EOF){
            printf("Files are different. They differ at position %d\n", pos);
            return;
        }
        if (c1 != c2){
            printf("Files different at position %d\n", pos);
            return;
        }
        pos++;
    }
    
}

int main(){
    FILE *f1, *f2;
    f1 = fopen("file1.dat", "rb");
    f2 = fopen("file2.dat", "rb");
    if (f1 == NULL || f2 == NULL){
        printf("File error\n");
        return 1;
    }
    else{
        binCompare(f1, f2);
    }
    fclose(f1);
    fclose(f2);
    return 0;
}