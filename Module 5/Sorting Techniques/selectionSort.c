#include <stdio.h>

void main(){
    printf("\nEnter the size of the array: ");
    int n;
    scanf("%d", &n);
    printf("\nEnter the Array to be sorted: ");
    int arr[MAX];
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    // Selection Sorting:
    int temp = 0;
    for(int i=0; i<n; i++){
        int min = arr[i];
        for(int j = i+1; j<n; j++){
            int check = arr[j];
            if(min > check){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    // Printing the Sorted Array:
    printf("\nSorted Array is: ");
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    return 0;
}