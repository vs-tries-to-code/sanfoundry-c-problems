//This C Program segregates 0s on left side & 1s on right side of the array.
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
    int left=0;
    int right=n-1;
    while (left<=right){
        if (arr[left]==0){
            if (arr[left]!=arr[right]){
                left++;
                right--;
            }
            else{
                left++;
            }
        }
        else{
            if (arr[left]!=arr[right]){
                int temp=arr[left];
                arr[left]=arr[right];
                arr[right]=temp;
                left++;
                right--;
            }
            else{
                right--;
            }
        }

    }

    for (int i=0; i<n; i++){
        printf("%d ", arr[i]);

    }
    return 0;
}