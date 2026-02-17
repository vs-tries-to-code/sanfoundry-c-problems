//This C Program Identifies the Missing Number in an Integer Array of Size N-1 with Numbers[1,N].
#include <stdio.h>
int main(){
    int n; 
    printf("Enter upper limit of elements: ");
    scanf("%d", &n);
    int arr[n]; 
    printf("Enter elements in the array: ");
    for(int i=0; i<n-1; i++){
        scanf("%d", &arr[i]);
    } 
    
    for (int i=1; i<=n; i++){
       int flag=0;
       for (int j=0; j<n; j++){
        if (arr[j]==i){
            flag=1;
            break;
        }
       }
       if (flag==0){
        printf("%d is missing\n", i);
       } 
    }

    return 0;
}