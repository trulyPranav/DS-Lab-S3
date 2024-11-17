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

void displayOdd(struct Node *head){
    if(head == NULL)
        printf("\nList Empty!!");
    else{
        struct Node *current = head -> next;
        printf("\nCurrent Linked List is: ");
        while(current != NULL){
            printf("%d -> ", current->data);
            if(current -> next != NULL)
                current = current -> next -> next;
            else break;
        }
        printf("NULL");
    }
}

void displayEven(struct Node *head){
    if(head == NULL || head -> next == NULL)
        printf("\nList Empty!!");
    else{
        struct Node *current = head;
        printf("\nCurrent Linked List is: ");
        while(current != NULL){
            printf("%d -> ", current->data);
            if(current->next != NULL)
                current = current -> next -> next;
            else break;
        }
        printf("NULL");
    }
}


int main(){
    while(1){
        printf("\n1)Insert at the Beginning of the list\n2)Display\n3)Display ODD\n4)Display EVEN\n5)Exit\nChoose the Operation: ");
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
                displayOdd(head);
                break;
            case 4:
                displayEven(head);
                break;
            case 5:
                exit(1);
            default:
                printf("\nChoose a valid Operation!");
        }
    }
    return 0;
}