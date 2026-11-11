#include <stdio.h>
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partitionArr(int arr[], int l, int h){
    int pivot = arr[l];
    int i = l + 1   ;
    int j = h;
    while(i<j){
        while(i <= h && arr[i] < pivot){
            i++;
        }

        while (arr[j] > pivot){
            j--;
        }

        if (i<j){
            swap(&arr[i], &arr[j]);
            i++; j--;
        }
    }
    swap(&arr[l], &arr[j]);

    return j;
}

void quickSort(int arr[], int l, int h){
    if (l < h){
        int j = partitionArr(arr, l, h);
        quickSort(arr, l, j-1);
        quickSort(arr, j+1, h);
    }
}

int main(){
    int n;
    printf("Enter size of array:\n");
    scanf("%d", &n);
    int arr[n];
    
    printf("Enter elements\n");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, n-1);
    
    printf("Sorted array\n");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}