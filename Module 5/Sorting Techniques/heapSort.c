#include <stdio.h>
#define MAX 100

void heapify(int arr[], int n, int i){
    int gr8est = i;
    int leftChild = 2*i+1;
    int rightChild = 2*i+2;

    if(leftChild < n && arr[leftChild] > arr[gr8est])
        gr8est = leftChild;
    
    if(rightChild < n && arr[rightChild] > arr[gr8est])
        gr8est = rightChild;
    
    if(gr8est != i){
        int temp = arr[i];
        arr[i] = arr[gr8est];
        arr[gr8est] = temp;
        heapify(arr,n,gr8est);
    }
}

void heapSort(int arr[], int n){
    for(int i=n/2-1; i>=0; i--)
        heapify(arr, n, i);
    for(int i=n-1; i>0; i--){
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr,i,0);
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
    // Heap Sorting:
    heapSort(arr,n);
    // Printing the Sorted Array:
    printf("\nSorted Array is: ");
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);        
    return 0;
}