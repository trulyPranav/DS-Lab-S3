#include <stdio.h>
#define MAX 100

int linearSearch(int arr[], int size, int target){
    for(int i=0; i<size; i++){
        if(arr[i] == target){
            return i;
            break;
        }
    }
    return -1;
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
    int result = linearSearch(arr, n, target);
    if(result == -1)
        printf("Element not found in given array!");
    else 
        printf("Element %d found at index %d, i.e. position %d\n", target, result, result+1);
    return 0;
}