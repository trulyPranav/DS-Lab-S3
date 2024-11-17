#include <stdio.h>
#include <stdlib.h>

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

void deleteEven(struct Node *head){
    if(head == NULL)
        printf("List Empty!");
    struct Node *preCurrent = head;
    struct Node *current = head->next;
    while(current != NULL){
        preCurrent -> next = current -> next;
        free(current);
        if(preCurrent->next != NULL){
            preCurrent = preCurrent->next;
            current = preCurrent -> next;
        }
        else break;
    }
}

void displayLinkedList(struct Node *head){
    if(head == NULL)
        printf("\nList Empty!!");
    else{
        struct Node *current = head;
        printf("\nCurrent Linked List is: ");
        while(current != NULL){
            printf("%d -> ", current->data);
            current = current -> next;
        }
        printf("NULL");
    }
}

int main(){
    while(1){
        printf("\n1)Insert at the Beginning of the list\n2)Display\n3)Delete EVEN\n4)Exit\nChoose the Operation: ");
        int opr;
        scanf("%d", &opr);
        switch(opr){
            case 1:
                printf("\nEnter element to insert: ");
                int elm;
                scanf("%d", &elm);
                head = insertRear(head, elm);
                break;
            case 2:
                displayLinkedList(head);
                break;
            case 3:
                deleteEven(head);
                break;
            case 4:
                exit(1);
            default:
                printf("\nChoose a valid Operation!");
        }
    }
    return 0;
}