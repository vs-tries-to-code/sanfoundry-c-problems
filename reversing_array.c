//Write a program to reverse an array in C (in place)
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
    int i=0; int j=n-1;
    while (i<=j){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i++;
        j--;
    }
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    } 

    
}