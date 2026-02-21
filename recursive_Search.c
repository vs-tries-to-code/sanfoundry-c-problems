//This C Program uses recursive function & searches for an element in an unsorted list and display it’s position of occurrence. The user enters the element needed to be searched.
#include <stdio.h>
int Searchfor(int arr[], int size, int target);
int main(){
    int n, target;
    printf("Enter number of elements in array: ");
    scanf("%d", &n); int arr[n];
    printf("Enter elements in the array: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    } 
    printf("Enter target element to search: ");
    scanf("%d", &target);
    int x=Searchfor(arr, n-1, target);
    if (x==-1){
        printf("element not found");
    }
    else{
        printf("Element found at index %d", x);
    }
    
    return 0;
    
}

int Searchfor(int arr[], int size, int target){
    if (size==-1){
        return -1;
    }
    if (arr[size]==target){
        return size;
    }
    else{
        return Searchfor(arr, size-1, target);
    }
}