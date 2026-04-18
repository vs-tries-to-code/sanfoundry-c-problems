#include <stdio.h>

#define MAX 10

int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX] = {0};
int m, n, p;

void multiply(int i, int j, int k){
    //base cases
    if (i >= m){
        return;
}

    if  (j >= p){
        multiply(i+1, 0, 0);
        return;
        
    }

    if (k < n){
        C[i][j] += A[i][k]*B[k][j];
        multiply(i,j,k+1);
    }
    else{
        multiply(i, j+1, 0);
    }
}

int main(){
    printf("Enter rows and cols of A: ");
    scanf("%d %d", &m, &n);

    printf("Enter cols of B: ");
    scanf("%d", &p);

    printf("Enter matrix A:\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("Enter matrix B:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < p; j++)
            scanf("%d", &B[i][j]);
    

    multiply(0,0,0);

}