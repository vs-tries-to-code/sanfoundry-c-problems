//C program to exchange elements of the primary diagonal with the secondary diagonal
//Note that the swapping is done for square matrices so that the elements of the primary diagonal have a one to one mapping with the secondary diagonal elements
#include <stdio.h>
int main(){
    int k;
    printf("Enter the number of rows of the square matrix: ");
    scanf("%d", &k);
    int matrix[k][k];
    printf("Enter elements of matrix\n");
    for (int i=0; i<k; i++){
        for (int j=0; j<k; j++){
            scanf("%d", &matrix[i][j]);
        }
        printf("\n");
    }

    for (int i=0; i<k; i++){
        for (int j=0; j<k; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    for (int i=0; i<k; i++){
        for (int j=0; j<k; j++){
            if (i==j){
                int temp=matrix[i][j];
                matrix[i][j]=matrix[i][k-j-1];
                matrix[i][k-j-1]=temp;
            }
        }
    }

    printf("Matrix after diagonal interchange\n");
    for (int i=0; i<k; i++){
        for (int j=0; j<k; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}