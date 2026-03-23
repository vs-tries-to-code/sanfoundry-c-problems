//To multiply two matrices, if possible
#include <stdio.h>
int main(){
    int r1, r2, c1, c2;
    printf("Enter number of rows of first matrix\n");
    scanf("%d", &r1);
    printf("Enter number of columns of first matrix\n");
    scanf("%d", &c1);
    int a[r1][c1];
    printf("Enter elements of first matrix\n");
    for (int i=0; i<r1; i++){
        for (int j=0; j<c1; j++){
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter number of rows of second matrix\n");
    scanf("%d", &r2);
    printf("Enter number of columns of second matrix\n");
    scanf("%d", &c2);
    int b[r2][c2];
    printf("Enter elements of first matrix\n");
    for (int i=0; i<r2; i++){
        for (int j=0; j<c2; j++){
            scanf("%d", &a[i][j]);
        }
    }

    if (c1 != r2){
        printf("Matrix multiplication not possible");
        return 0;
    }

    int c[r1][c2];
    for (int i=0; i<r1; i++){
        for (int j=0; j<c2; j++){
            c[i][j]=0;
            for (int k=0; k<c1; k++){
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("Multiplied matrix\n");
    for (int i=0; i<r1; i++){
        for (int j=0; j<c2; j++){
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    return 0;

}