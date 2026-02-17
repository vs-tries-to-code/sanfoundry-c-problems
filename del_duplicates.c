//Write a C Program to remove duplicate elements from an Array.
#include <stdio.h>
int main(){
    int n; 
    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    int arr[n]; int arr1[n];
    printf("Enter elements in the array: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    } 
    //keeps track of unique elements in array
    int k=0;
    for (int i=0; i<n; i++){
        //to check whether an element occurs more than once in an array
        int count=0;
        for (int j=i+1; j<n; j++){
            if (arr[i]==arr[j]){
                count++;
                break;
            }
        }
        if (count==0){
            arr1[k]=arr[i];
            k++;
        }
    }
    for(int i=0; i<k; i++){
        printf("%d ", arr1[i]);
    } 
    return 0;
}
    