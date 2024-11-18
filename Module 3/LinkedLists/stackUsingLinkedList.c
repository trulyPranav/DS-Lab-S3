#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

struct Node *enqueueRear(struct Node *head, int newData){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = newData;
    newNode -> next = NULL;
    if(head == NULL)
        head = newNode;
    else {
        struct Node *current = head;
        while(current -> next != NULL){
            current = current->next;
        }
        current -> next = newNode;
    }
    printf("\nElement Enqueued Successfully!\n");
    return head;
}

struct Node *dequeueRear(struct Node *head){
    if(head == NULL){
        printf("\nStack Empty!\n");
        return head;
    }
    struct Node *current = head;
    struct Node *preCurrent = NULL;
    while(current -> next != NULL){
        preCurrent = current;
        current = current->next;
    }
    if(preCurrent == NULL){
        free(head);
        head = NULL;
    } else {
        preCurrent -> next = NULL;
        free(current);
    }
    printf("\nDeQueue Successfull\n");
    return head;

}

void display(struct Node *head){
    if(head == NULL)
        printf("\nStack Empty!\n");
    else {
        struct Node *current = head;
        printf("Stack is:\n");
        while(current != NULL){
            printf("%d\n", current -> data);
            current = current->next;
        }
        printf("END\n");
    }
}

int main(){
    printf("WELCOME TO STACK OPERATIONS!\n");
    while(1){
        printf("What do you need?\n1)Enqueue Element\n2)Dequeue Element\n3)Display Stack\n4)EXIT\nChoose: ");
        int opr;
        scanf("%d", &opr);
        switch(opr){
            case 1:
                printf("\nEnter the Element to insert: ");
                int elm;
                scanf("%d", &elm);
                head = enqueueRear(head, elm);
                break;
            case 2:
                head = dequeueRear(head);
                break;
            case 3:
                display(head);
                break;
            case 4:
                exit(1);
                break;
            default:
                printf("\nEnter a Valid Operarion!\n");
                break;
        }
    }
}