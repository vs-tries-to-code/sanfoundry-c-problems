//This C Program displays the number of lines in a text file.

#include <stdio.h>
int main(){
    FILE *f;
    f = fopen("text.txt", "r");

    if (f == NULL){
        printf("File error\n");
        return 1;
    }
    
    //using fgets
    char line[100];
    int countline = 0;
    while (fgets(line, sizeof(line), f)){
        countline++;
    }
    printf("Number of lines in text.txt (fgets) : %d\n", countline);
    
    //set file pointer to the beginning 
    fseek(f, 1, SEEK_SET);

    //using fgetc
    char c; int lines = 0;
    while ((c = fgetc(f)) != EOF){
        if (c == '\n'){
            lines++;
        }
        c = fgetc(f);
    }
    printf("Number of lines in text.txt (fgetc): %d\n", lines+1); //lines + 1 !
    fclose(f);
    
    return 0;
}