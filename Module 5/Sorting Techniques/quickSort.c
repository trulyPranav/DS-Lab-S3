#include <stdio.h>
#define MAX 100

int partition(int arr[], int first, int last){
    int pivot = arr[last];
    int i = first - 1;

    for(int j=first; j<last; j++){
        if(arr[j] <= pivot){
            i++;
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    int temp = arr[last];
    arr[last] = arr[i+1];
    arr[i+1] = temp;
    return i+1;
}

void quickSort(int arr[], int left, int right){
    if(left < right){
        int pivotIndex = partition(arr, left, right);
        quickSort(arr,left,pivotIndex-1);
        quickSort(arr,pivotIndex+1,right);
    }
}

int main(){
    printf("\nEnter the size of the array: ");
    int n;
    scanf("%d", &n);
    printf("\nEnter the Array to be sorted: ");
    int arr[MAX];
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    // Quick Sorting:
    quickSort(arr,0,n-1);
    // Printing the Sorted Array:
    printf("\nSorted Array is: ");
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);        
    return 0;
}