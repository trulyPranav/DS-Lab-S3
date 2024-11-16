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
        
    // Insertion Sorting;
    int prev,key;
    // Start from the first index:
    for(int i=1; i<n; i++){
        key = arr[i];
        prev = i-1;
        while(prev>=0 && arr[prev] > key){
            arr[prev+1] = arr[prev];
            prev --;
        }
        arr[prev+1] = key;
    }
    // Printing the Sorted Array:
    printf("\nSorted Array is: ");
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    return 0;
}