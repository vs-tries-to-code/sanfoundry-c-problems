//This program implements a one dimentional array, sorts it and then takes a user input and inserts the desired element in the specified position of a one dimentional array and print all the elements of the array with a +1 increment in the array size.
#include <stdio.h>
int main(){
    int n; int key; int pos;
    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    int arr[n+1];
    printf("Enter elements in the array: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    for (int i=0; i<n; i++){
        for (int j=1+i; j<n; i++){
            if (arr[i]>arr[j]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    printf("Sorted array\n");
    for(int i=0; i<n; i++){
        printf("%d\n", arr[i]);
    }
    printf("Enter element to be added: ");
    scanf("%d", &key);
    
    for (int i=0; i<n; i++){
        if (key<arr[i]){
            pos=i;
            break;
        }
        if (key>arr[n-1]){
            pos=n;
            break;

        }
    }
    
    for (int i=0; i<n; i++){
        if (arr[i]< key){
            for (int j=n; j>i; j--){
                arr[j]=arr[j-1];
            }
            arr[pos]=key;
        }
    }

    printf("Final array: ");
    for (int i=0; i<=n; i++){
        printf("%d ", arr[i]);
    }

    return 0;

}