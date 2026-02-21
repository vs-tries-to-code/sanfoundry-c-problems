//This program will split an array from specified position & add first part to the end
#include <stdio.h>
int main(){
    int n; int pivot;
    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    int arr[n]; int arr1[n];
    printf("Enter elements in the array: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    } 
    printf("Enter the position to split: ");
    scanf("%d", &pivot);
    int k=0; 
    for (int i=pivot; i<n; i++){
        arr1[k]=arr[i];
        k++;
    }

    for (int i=0; i<pivot; i++){
        arr1[k]=arr[i];
        k++;
    }

    for (int i=0; i<n; i++){
        printf("%d ", arr1[i]);
    }

    
    return 0;


}