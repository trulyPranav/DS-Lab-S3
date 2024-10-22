#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

struct Node *enqueueFront(struct Node *head, int newData){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = newData;
    newNode -> next = head;
    head = newNode;
    return head;
}

struct Node *enqueueRear(struct Node *head, int newData){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = newData;
    newNode -> next = NULL;

    if(head == NULL)
        head = newNode;
    else {
        struct Node *current = head;
        while(current->next!=NULL)
            current = current->next;
        current->next = newNode;
    }
    return head;
}

struct Node *enqueuePosition(struct Node *head, int pos,int newData){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = newData;
    newNode -> next = NULL;
    if(pos == 1){
        newNode -> next = head;
        head = newNode;
        return head;
    }
    struct Node *current = head;
    for(int i = 1; i<pos-1 && current!=NULL; i++)
        current = current->next;
    if(current == NULL){
        free(newNode);
        return head;
    }
    newNode -> next = current -> next;
    current -> next = newNode;
    return head;
}

struct Node *dequeueFront(struct Node *head){
    if(head == NULL){
        printf("\nNothing to Delete!");
        return head;
    }
    struct Node *newHead = head -> next;
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
    struct Node *preCurrent = NULL;
    while(current -> next != NULL){
        preCurrent = current;
        current = current -> next;
    }
    if(preCurrent == NULL){
        free(head);
        head = NULL;
    } else{
        preCurrent -> next = NULL;
        free(current);
    }

    printf("\nSuccessfully deleted from Rear");
    return head;
}

struct Node *dequeuePosition(struct Node *head, int position){
    if(head == NULL){
        printf("Nothing to Delete!");
        return head;
    }
    if(position == 1){
        struct Node *newHead = head;
        newHead = head -> next;
        free(head);
        printf("Element at Position %d Deleted!", position);
        return newHead;
    } else{
        struct Node *current = head;
        struct Node *preCurrent = current;
        for(int i=1; i<position && current!=NULL; i++){
            preCurrent = current;
            current = current -> next;
        }
        if(current == NULL){
            printf("\nInvalid Position!");
            return head;
        }
        preCurrent -> next = current -> next;
        free(current);
        printf("Element at Position %d Deleted!", position);
        return head;

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
    printf("Welcome to Singly Linked Lists!");
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
        }

    }
    return 0;
}