#include <stdio.h>
int main(){
    //this is the method that does not involve sorting
   int arr[5]={2,1,1,2,1};
   int largest1=arr[0];
   int largest2=arr[1] ;

   for (int i=0; i<5; i++){
    printf("%d ", arr[i]);
   }
   if (largest2>largest1){
    int temp=largest2;
    largest2=largest1;
    largest1=temp;
   }

   for (int i=2; i<5; i++){
    if (arr[i]>largest1){
        largest1=arr[i];
    }

    else if (arr[i]>largest2 && arr[i]!=largest1){
        largest2=arr[i];
    }
   }

   printf("Largest element: %d\n",largest1);
   printf("Second largest element: %d\n", largest2);

   return 0;

   //otherwise, sort the array in descending order and then print the first two elements (works only if the elements are unique)
}