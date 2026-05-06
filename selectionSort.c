//Implementing selection sort in C
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
    for (int i=0; i<n; i++){
        int min = arr[i];
        for (int j=i+1; j<n; j++){
            if (arr[j] < min){
                min = arr[j];
            }
        }
        int temp = arr[i];
        arr[i] = min;
        min = temp;
    }

    printf("Sorted elements\n");
    for (int i = 0; i<n; i++){
        printf("%d ", arr[i]);
    }

}