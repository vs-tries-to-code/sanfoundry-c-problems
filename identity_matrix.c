//Check whether a given matrix is an identity matrix or not
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
    if (row!=col){
        printf("Not an identity matrix.\n An identity matrix is a square matrix");
        return 0;
    }
    else{
        int flag=1;
        for (int i=0; i<row; i++){
            for (int j=0; j<col; j++){
                if (i==j && matrix[i][j]!=1){
                    flag=0;
                    break;
                }
                if (i!=j && matrix[i][j]!=0){
                    flag=0;
                    break;
                }
            }
        }

        if (flag==0){
            printf("The square matrix is not an identitiy matrix\n");
    
        }
        else{
            printf("The square matrix is an identity matrix\n");
        }
    }
    
    return 0;
}