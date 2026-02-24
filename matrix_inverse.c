//Code to find inverse of a square matrix, if invertible
#include <stdio.h>
#include <math.h>
float Det(int k, float a[k][k]);
void cofactor(int k, float a[k][k]);
void Transpose(int k, float a[k][k],float b[k][k]);

int main(){
    int k;
    printf("Enter rows of square matrix: ");
    scanf("%d", &k);  
    float matrix[k][k];
    printf("Enter elements of matrix\n");
    for (int i=0; i<k; i++){
        for (int j=0; j<k; j++){
            scanf("%f", &matrix[i][j]);
        }
        printf("\n");
    }
    float d=Det(k, matrix);
    if (d==0){
        printf("Matrix is not invertible");
    }
    else{
        cofactor(k, matrix);
    }
    return 0;
}

float Det(int k, float a[k][k]){
    float b[k-1][k-1]; float det=0;
    if (k==1){
        return (a[0][0]);
    }
    else{
        float s=1;
        for (int c=0; c<k; c++){
            int m=0, n=0;
            for (int i=1; i<k; i++){
                for (int j=0; j<k; j++){
                    if (j!=c){
                        b[m][n]=a[i][j];
                        n++;
                    }
                }
                n=0;
                m++;
            }
            det=det+ s*(a[0][c]* Det(k-1,b));
            s=-s;

        }
        return det;
    }
    
}

void cofactor(int k, float a[k][k]){
    float b[k][k]; float cofac[k][k];
    for (int i=0; i<k; i++){
        for (int j=0; j<k; j++){
            int m=0, n=0;
            for (int p=0; p<k; p++){
                for (int q=0; q<k; q++){
                    b[m][n]=a[i][j];
                    if (n<(k-2)){
                        n++;
                    }
                    else{
                        n=0;
                        m++;
                    }
                }
            }
            cofac[i][j]=pow(-1, i+j)* Det(k-1, b);
            
        }
    }
    Transpose(k,a,cofac);
}

void Transpose(int k, float a[k][k], float cofac[k][k]){
    float inverse[k][k];
    for (int i=0; i<k; i++){
        for (int j=0; j<k; j++){
            inverse[i][j]=cofac[j][i];
        }
    }
    float d=Det(k, a);
    for (int i=0; i<k; i++){
        for (int j=0; j<k; j++){
            printf("%f  ", inverse[i][j]/d);
        }
        printf("\n");
    }
}
