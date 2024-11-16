// Merge Sort mainly has 3 Functions: Merging Function, Sorting Function and the Main Function

#include <stdio.h>
#define MAX 100

void merge(int arr[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right-mid;
    int L[n1], R[n2];
    for(int i=0; i<n1; i++)
        L[i] = arr[left+i];
    for(int i=0; i<n2; i++)
        R[i] = arr[mid+1+i];
    int i = 0, j=0, k=left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }    
}

void mergeSort(int arr[], int left, int right){
    if(left < right){
        int mid = (left+right)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);

        //Merging:
        merge(arr, left, mid, right);
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
    // Merge Sorting:
    mergeSort(arr,0,n-1);
    // Printing the Sorted Array:
    printf("\nSorted Array is: ");
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);        
    return 0;
}