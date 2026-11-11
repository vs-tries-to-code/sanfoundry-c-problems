//implement countingSort (and use this for Radix Sort)
// O(n+x) n-> number of elements in array, x -> max element (elements belong to the range 0 to x)

#include <stdio.h>

int main(){
    int n, x;

    printf("Array must contain elements in the range (0 to x)\n");
    printf("Enter x:\n");
    scanf("%d", &x);

    printf("Enter number of elements in the array (duplicates allowed)\n");
    scanf("%d", &n);

    if (n <= 0 || x < 0) {
        printf("Invalid input\n");
        return 1;
    }

    int a[n];

    printf("Enter elements\n");

    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);

        if(a[i] < 0 || a[i] > x){
            printf("Element outside range\n");
            return 1;
        }
    }

    int b[n];
    int c[x+1];

    // initialize c - otherwise segmentation fault
    // O(x)
    for(int i = 0; i <= x; i++){
        c[i] = 0;
    }

    // frequency counting
    // O(n)
    for(int i = 0; i < n; i++){
        c[a[i]]++;
    }

    // cumulative frequency
    // O(x)
    for(int i = 1; i <= x; i++){
        c[i] += c[i-1];
    }

    // placement
    // O(n)
    for(int i = n-1; i >= 0; i--){
        int element = a[i];
        b[c[element]-1] = element;
        c[element]--;
    }

    // Print sorted array
    for(int i = 0; i < n; i++){
        printf("%d ", b[i]);
    }

    return 0;
}
