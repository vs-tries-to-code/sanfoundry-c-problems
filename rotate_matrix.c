//not a sanfoundry question. This was inspired from leetcode problem 48, but the approach is not inplace rotation. 
#include <stdio.h>
int main(){
    printf("Enter n:");
    int n;
    scanf("%d", &n);
    int arr[n][n];
    printf("Enter elements:\n");
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    int arr2[n][n];
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            arr2[j][n-i] = arr[i][j];
        }
    }
    printf("Rotated array\n");
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            printf("%d ", arr2[i][j]);
        }
        printf("\n");
    }

}