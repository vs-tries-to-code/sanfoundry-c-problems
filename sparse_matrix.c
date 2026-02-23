//Sparse matrix is a matrix with the majority of its elements equal to zero. However, there is no fixed ratio of zeros to non-zero elements. But it is believed that the number of 0’s should be strictly greater than half of the product of rows and columns in a matrix.
#include <stdio.h>
int  main(){
    int count=0;
    int row, col;
    printf("Enter number of rows in matrix: \n");
    scanf("%d", &row);
    printf("Enter number of columns in matrix: \n");
    scanf("%d", &col);
    int matrix[row][col];
    for (int i=0; i<row; i++){
        for (int j=0; j<col; j++){
            if (matrix[i][j]==0){
                count++;
            }
        }
    } 
    float sparse = (count/(row*col))*100.0;
    if (sparse>50.0){
        printf("The matrix is sparse\n");
    } 
    else{
        printf("The matrix is not sparse\n");
    }
    
    return 0;
}