#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

struct Node *enqueueFront(struct Node *head, int newData){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = newData;
    newNode -> prev = NULL;
    newNode -> next = head;
    if(head != NULL)
        head -> prev = newNode;
    return newNode;
}

struct Node *enqueueRear(struct Node *head, int newData){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = newData;
    newNode -> next = NULL;
    if(head == NULL){
        newNode -> prev = NULL;
        return newNode;
    }
    struct Node *current = head;
    while(current->next != NULL)
        current = current -> next;
    current -> next = newNode;
    newNode -> prev = current;
    return head; 
}

struct Node *enqueuePosition(struct Node *head, int position, int newData){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = newData;
    if(position == 1){
        newNode -> next = head;
        newNode -> prev = NULL;
        if(head != NULL)
            head -> prev = newNode;
        return newNode;
    }
    struct Node *current = head;
    for(int i=1; i<position-1 && current !=NULL; i++)
        current = current -> next;
    if(current == NULL){
        free(current);
        return head;
    }
    // Assigning Logic Below:
    newNode -> next = current ->next;
    newNode -> prev = current;
    current -> next = newNode;
    if(newNode -> next != NULL)
        newNode -> next -> prev = newNode;
    return head;
}

struct Node *dequeueFront(struct Node *head){
    if(head == NULL){
        printf("\nNothihg to Delete!");
        return head;
    }
    struct Node *newHead = head -> next;
    if(newHead != NULL)
        newHead -> prev = NULL;
    free(head);
    printf("\nSuccessfully deleted from Front");
    return newHead;
}

struct Node *dequeueRear(struct Node *head){
    if(head == NULL){
        printf("\nNothing to Delete!");
        return head;
    }
    struct Node *current = head;
    while(current -> next != NULL)
        current = current -> next;
    if(current -> prev != NULL)
        current -> prev -> next = NULL;
    else{
        // free(head);
        head = NULL;
    }
    free(current);
    printf("\nSuccessfully deleted from Rear");
    return head;

}

struct Node *dequeuePosition(struct Node *head, int position){
    if(head == NULL){
        printf("\nNothing to Delete!");
        return head;
    }
    if(position == 1){
        struct Node *newHead = head -> next;
        if(newHead != NULL)
            newHead -> prev = NULL;
        free(head);
        printf("\nElement at Position %d Deleted!", position);
        return newHead;
    }
    struct Node *current = head;
    for(int i=1; i<position && current != NULL; i++)
        current = current -> next;
    if(current == NULL){
        printf("\nInvalid Position!");
        free(current);
        return head;
    }
    // Assigning Logic:
    current -> prev -> next = current -> next;
    if(current->next != NULL)
        current -> next -> prev = current -> prev;
    free(current);
    printf("\nElement at Position %d Deleted!", position);
    return head;
}

void displayLinkedList(){
    if(head == NULL)
        printf("\nList Empty!");
    else {
        struct Node *current = head;
        printf("\nCurrent Linked List is: NULL -> ");
        while(current != NULL){
            printf(" %d -> ", current -> data);
            current = current -> next;
        }
        printf("NULL");
    }
}

int main(){
    printf("Welcome to Doubly Linked Lists!");
    while(1){
        printf("\n1)Insert at the Beginning of the list\n2)Insert at the End of the list\n3)Insert at a Specific Position of the list\n4)Delete from the Beginning\n5)Delete from the End\n6)Delete from a Specific Position\n7)Display Linked List\n8)Exit\nChoose the Operation: ");
        int opr;
        scanf("%d", &opr);
        switch(opr){
            case 1:
                printf("\nEnter element to insert: ");
                int elm;
                scanf("%d", &elm);
                head = enqueueFront(head, elm);
                break;
            case 2:
                printf("\nEnter element to insert: ");
                int revElm;
                scanf("%d", &revElm);
                head = enqueueRear(head, revElm);
                break;
            case 3:
                printf("\nEnter element to insert: ");
                int posElm;
                scanf("%d", &posElm);
                printf("\nEnter position to insert: ");
                int pos;
                scanf("%d",&pos);
                head = enqueuePosition(head,pos,posElm);
                break;
            case 4:
                head = dequeueFront(head);
                break;
            case 5:
                head = dequeueRear(head);
                break;
            case 6:
                int delPos;
                printf("\nEnter list position to delete: ");
                scanf("%d",&delPos);
                head = dequeuePosition(head,delPos);
                break;
            case 7:
                displayLinkedList(head);
                break;
            case 8:
                exit(1);
            default:
                printf("\nChoose a valid Operation!");
        }
    }
}