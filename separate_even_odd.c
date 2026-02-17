//The program first finds the odd and even elements of the array. Then the odd elements of an array is stored in one array and even elements of an array is stored in another array.
#include <stdio.h>
int main(){
    int n; 
    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    int arr[n]; int even[n]; int odd[n];
    printf("Enter elements in the array: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    } 
    int len1=0;
    int len2=0;
    for (int i=0; i<n; i++){
        if (arr[i]%2==0){
            even[len1]=arr[i];
            len1++;
        }
        else{
            odd[len2]=arr[i];
            len2++;
        }

    }

    printf("Even elements\n");
    for(int i=0; i<len1; i++){
        printf("%d ", even[i]);

    }
    printf("\n");

    printf("Odd elements\n");
    for(int i=0; i<len2; i++){
        printf("%d ", odd[i]);

    }
    return 0;

}