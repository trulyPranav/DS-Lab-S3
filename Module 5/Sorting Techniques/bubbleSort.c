#include <stdio.h>
#define MAX 100

int main(){
    printf("\nEnter the size of the array: ");
    int n;
    scanf("%d", &n);
    printf("\nEnter the Array to be sorted: ");
    int arr[MAX];
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    // Bubble Sorting:
    int temp = 0;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    // Printing the Sorted Array:
    printf("\nSorted Array is: ");
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);

    return 0;
}