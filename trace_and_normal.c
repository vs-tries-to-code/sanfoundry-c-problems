//C program to find the trace and normal of a matrix
#include <stdio.h>
int main(){
    int row, col;
    printf("Enter number of rows:");
    scanf("&d", &row);
    printf("Enter number of columns: ");
    scanf("%d", &col);
    if (row>0 && col>0){
        int trace=0;
        float sum=0;
        int matrix[row][col];
        printf("Enter elements of matrix\n");
        for (int i=0; i<row; i++){
        for (int j=0; j<col; j++){
            scanf("%d", &matrix[i][j]);
        }
        printf("\n");
        }  

        for (int i=0; i<row; i++){
        for (int j=0; j<col; j++){
            printf("%d", matrix[i][j]);
        }
        printf("\n");
        }

        for (int i=0; i<row; i++){
            for (int j=0; j<col; j++){
                if (i==j){
                    trace+=matrix[i][i];
                }
                sum+=matrix[i][j];
            }
        }

        float normal = pow(sum, 0.5);
        printf("Trace of matrix: %d\n", trace);
        printf("Normal of matrix: %f", normal);


    }
    else{
        printf("Matrix of given dimension is not possible");
        return 0;
    }

    return 0;
}