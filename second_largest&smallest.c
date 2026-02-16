//The program will implement a one dimentional array and sort the array in descending order. Then it finds the second largest and smallest element in an array and also find the average of these two array elements. Later it checks if the resultant average number is present in a given array. If found, display appropriate message

#include <stdio.h>
int main(){
    int arr[4]={340, 120, 450, 670};
    for (int i=0; i<4; i++){
        for (int j=0; j<4-i-1; j++){
            if (arr[j]<arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=arr[j];
            }
        }
    }
    int second_largest=arr[1];
    int second_smallest=arr[4-2];
    printf("Second largest element: %d\n", second_largest);
    printf("Second smallest element: %d\n", second_smallest);

    float avg=(second_largest + second_smallest)/2.0;
    printf("Average = %f\n", avg);
    
    for (int i=0; i<4; i++){
        if (avg==arr[i]){
            printf("Average found at index: %d\n", i);
        }
    }

    return 0;
}