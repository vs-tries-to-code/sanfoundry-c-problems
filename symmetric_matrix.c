//to check whether a given matrix is symmetric or not 
#include <stdio.h>
int main(){
    int row, col;
    printf("Enter number of rows in matrix: \n");
    scanf("%d", &row);
    printf("Enter number of columns in matrix: \n");
    scanf("%d", &col);
    int matrix[row][col];
    if (row!=col){
        printf("Not a symmetric matrix.\nThe transpose of a non square matrix of dimension (n*m) would have different dimension (m*n)");
        return 0;
    }
    else{
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


        int flag=1;
        for (int i=0; i<row; i++){
            for (int j=0; j<row; j++){
                if (matrix[i][j]!=matrix[j][i]){
                    flag=0;
                    break;
                }
            }
        }
        if (flag==0){
            printf("The matrix isn't symmetric");

        }
        else{
            printf("The matrix is symmetric");
        }
    }

    
    return 0;
}