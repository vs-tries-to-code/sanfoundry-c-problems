//program to convert a matrix to an lower triangular matrix

#include <stdio.h>
int main(){
    int row, col;
    printf("Enter number of rows in matrix: \n");
    scanf("%d", &row);
    printf("Enter number of columns in matrix: \n");
    scanf("%d", &col);
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
            if (j>i){
                matrix[i][j]=0;
            }
        }
    }

    printf("Lower triangular matrix\n");
    for (int i=0; i<row; i++){
        for (int j=0; j<col; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

//If it was j<i then it would be the code to convert the given matrix to an upper triangular matrix
//In order to check whether a matrix is upper triangular or not introduce flag variable and break the loop if any of the elements below the main diagonal is non zero.