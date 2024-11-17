#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

struct Node *insertRear(struct Node *head, int newData){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = newData;
    newNode -> next = NULL;
    if(head == NULL)
        head = newNode;
    else {
        struct Node *current = head;
        while(current -> next != NULL)
            current = current->next;
        current->next = newNode;
    }
    return head;
}

void sort(int arr[], int num){
    for(int i=0; i<num; i++){
        head = insertRear(head, arr[i]);
    }
    struct Node *i,*j;
    for(i=head; i != NULL; i = i->next){
        for(j = i->next; j!=NULL; j=j->next){
            if(i->data > j->data){
                int temp = i->data;
                i->data = j -> data;
                j -> data = temp;
            }
        }     
    }
    struct Node *print = head;
    while(print != NULL){
        printf("%d ", print->data);
        print = print -> next;
    }
}

int main(){
    int num;
    printf("Enter the Array Size: ");    
    scanf("%d", &num);
    printf("Enter the Array to sort: ");
    int arr[MAX];
    for(int i=0; i<num; i++){
        scanf("%d", &arr[i]);
    }
    sort(arr,num);
    // for(int i=0; i<num; i++){
    //     printf("%d ", arr[i]);
    // }    
}