#include <stdio.h>

struct Mat{
    int row;
    int col;
    int val;
};

typedef struct Mat element;

void addSparseMatrix(element a[], element b[], element result[]){
    result[0].row = a[0].row;
    result[0].col = a[0].col;

    int i=0, j=0, k=0;
    while(i <= a[0].val && j <= b[0].val){
        if(a[i].row < b[j].row){
            result[k++] = a[i++];
        }
        else if (a[i].row > b[j].col){
            result[k++] = b[j++];
        }
        else{
            if(b[j].col < a[i].col){
                result[k++] = b[j++];
            }

            else if (a[i].col < b[j].col){
                result[k++] = a[i++];
            }

            else{
                int sum = a[i].val  + b[j].val;
                if (sum != 0) {
                    element temp;
                    temp.col = a[i].col;
                    temp.row = a[i].row;
                    temp.val = sum;
                    result[k++] = temp;
                }
                i++;j++;
            }
        }
    }

    while(i < a[0].val){
        result[k++] = a[i];
    }

    while(j < b[0].val){
        result[k++] = b[j];
    }

    result[0].val = k-1;
    
}

void transpose(element trans[], element a[], element out[]){
    trans[0].row = a[0].col;
    trans[0].col = a[0].row;
    trans[0].val = a[0].val;

    int k=0;
    //for each column, iterate as many times as there are non-zero values in the matrix
    for(int i=0; i<a[0].col; i++){
        for(int j=1; j <= a[0].val; j++){
            if (a[j].col == i){
                out[k].col = a[j].row;
                out[k].row = a[j].col;
                out[k].val = a[j].val;
                k++;
            }
        }
    }
}