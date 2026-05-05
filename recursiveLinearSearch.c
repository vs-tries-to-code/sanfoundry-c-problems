//Create a C Program which finds the position of an element in an array using Linear Search Algorithm using Recursion
#include <stdio.h>
int linSearch(int arr[], int target, int start, int end);
int main(){
    int n, target;
    printf("Enter number of elements:");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements\n");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Enter target element:");
    scanf("%d", &target);
    int x = linSearch(arr, target, 0, n-1);
    if (x == 0){
        printf("Target not found\n");
    }
    else{
        printf("Target found at position %d\n", x);
    }

    return 0;
}

int linSearch(int arr[], int target, int start, int end){
    int position = 0;
    if (start >= end){
        return 0;
    }
    else if (arr[start] == target){
        position = start + 1;
        return position;
    }
    else{
        return linSearch(arr, target, start+1, end);
    }
    
}