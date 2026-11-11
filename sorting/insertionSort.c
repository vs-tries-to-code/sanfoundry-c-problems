//C program to implement insertion sort
#include <stdio.h>
int main(){
    int n;
    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    printf("Enter elements\n");
    int arr[n];
    for (int i = 0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    for (int i = 1; i < n; i++){
        int j = i;
        while (j > 0){
            if (arr[j-1] > arr[j]){
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
            j--;
        }
    }

    printf("Sorted elements\n");
    for (int i = 0; i<n; i++){
        printf("%d ", arr[i]);
    }


}