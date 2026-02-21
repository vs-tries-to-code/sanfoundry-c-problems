//find mode in an array
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
    int mode=arr[0];
    for (int i=0; i<n; i++){
        int count=0;
        for (int j=0; j<n; j++){
            if (arr[i]==arr[j]){
                count++;
            }
        }
        if (count>=mode){
            mode=count;
        }
        
    }


}