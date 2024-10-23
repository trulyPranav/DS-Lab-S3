// Merge Sort mainly has 3 Functions: Merging Function, Sorting Function and the Main Function

#include <stdio.h>
#define MAX 100

void merge(int arr[], int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r-m;
    int L[n1], R[n2];
    for(int i=0; i<n1; i++)
        L[i] = arr[l+i];
    for(int i=0; i<n2; i++)
        R[i] = arr[m+1+i];
    int i = 0, j=0, k=l;
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
        int m = (left+right)/2;
        mergeSort(arr, left, m);
        mergeSort(arr, m+1, right);

        //Merging:
        merge(arr, left, m, right);
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