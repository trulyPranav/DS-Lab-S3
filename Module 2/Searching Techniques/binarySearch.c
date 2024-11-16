#include <stdio.h>
#define MAX 100

int binarySearch(int arr[], int left, int right, int target){
    if(left<=right){
        int mid = left+(right-left)/2;
        if(target == arr[mid])
            return mid;
        if(target < arr[mid])
            return binarySearch(arr, left, mid-1, target);
        if(target > arr[mid])
            return binarySearch(arr, mid+1, right, target);
    }
    return -1;
}

void sort(int arr[], int size){
    int temp = 0;
    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-i-1; j++){
            if(arr[j] >= arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    printf("\nEnter the size of the array: ");
    int n;
    scanf("%d", &n);
    printf("\nEnter the Array: ");
    int arr[MAX];
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    int target;
    printf("Enter the target element to search: ");
    scanf("%d", &target);
    sort(arr, n);
    int result = binarySearch(arr, 0, n-1, target);
    if(result == -1)
        printf("Element not found in given array!");
    else 
        printf("Element %d found at index %d, i.e. position %d\n", target, result, result+1);
    return 0;
}