//Cyclically permute an array: I/P=[1,2,3,4] => O/P=[2,3,4,1]
#include <stdio.h>
int main(){
    int n; 
    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements in the array: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    } 
    int temp=arr[0];
    for (int i=0; i<n-1; i++){
        arr[i]=arr[i+1];
    }
    arr[n-1]=temp;

    printf("Rotated array\n");
    for (int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}