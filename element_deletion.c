//Write a C Program to delete an element in an Array by index or value.
#include <stdio.h>
int main(){
    int n; int index;
    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements in the array: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Enter index of element to be deleted: ");
    scanf("%d", &index);
    
    if (index > n-1 || index < 0){
        printf("Out of bounds\n");
        return 0;
    }
    else{
        for (int i=index; i<n-1; i++){
            arr[i]=arr[i+1];
        }
        
        for (int i=0; i<n-1; i++){
            printf("%d ", arr[i]);
        }
    }
}