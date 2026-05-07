/* This is a C Program to Compute the Sum of two One-Dimensional Arrays using malloc().
    If we are entering 5 elements (N=5) in both arrays with arrays elements values as 23, 45, 67, 12, 90 and 87, 56, 90, 45, 10 respectively, then the resultant array will have values as 110, 101, 157, 57, 100.
*/
#include <stdio.h>
#include <stdlib.h>
void fillArr(int arr[], int n){
    printf("Enter elements of array\n");    
    for (int i =0; i<n; i++){
        scanf("%d", &arr[i]);
    }
}
int main(){
    int n;
    printf("Enter number of elements in both arrays:");
    scanf("%d", &n);
    int *arr1 = (int *)malloc(n * sizeof(int));
    int *arr2 = (int *)malloc(n * sizeof(int));
    int *arr3 = (int *)malloc(n * sizeof(int));
    
    fillArr(arr1, n);
    fillArr(arr2, n);

    for (int i=0; i<n; i++){
        arr3[i] = arr1[i] + arr2[i];
    }

    printf("New array\n");
    for(int i=0; i<n; i++){
        printf("%d ", arr3[i]);
    }
    
    return 0;
}