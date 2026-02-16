#include <stdio.h>
int main(){
    int array[] = {10, 15, 90, 200, 110};
    int size=5;
    
    int max_diff = array[1]-array[0];
    for (int i=0; i<5; i++){
        for (int j=i+1; j<5; j++){
            if (array[j]-array[i]>max_diff){
                max_diff=array[j]-array[i];
            }
        }
    }

    printf("Maximum difference = %d", max_diff);
    return 0;
}