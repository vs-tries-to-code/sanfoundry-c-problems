//This C Program finds the size of file 
#include <stdio.h>
int main(){
    FILE *f;
    f = fopen("text.txt", "r");
    if ( f == NULL ){
        printf("File error\n");
        return 1;
    }

    //without using function
    int count = 0;
    int c;
    while ((c = fgetc(f)) != EOF ){
        count++;
    }
    printf("Size of file (without function)= %d\n", count);
    printf("This is the number of characters in the file\n");

    rewind(f);
    //using function
    fseek(f, 0, SEEK_END);
    int size = ftell(f);

    printf("Size of file (using function) : %d\n", size);
    printf("This is the actual size of the file, as the \\n is stored in two bytes\n");
    

    fclose(f);

    return 0;


}