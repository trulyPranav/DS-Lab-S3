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
    if(head == NULL){
        newNode -> next = newNode;
        head = newNode;
    } else {
        newNode -> next = head;
        struct Node *last = head;
        while(last->next != head)
            last = last->next;
        last -> next = newNode;
        head = newNode;
    }
    return head;
}

struct Node *enqueueRear(struct Node *head, int newData){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = newData;
    if(head == NULL){
        newNode -> next = newNode;
        head = newNode;
    } else {
        newNode -> next = head;
        struct Node *last = head;
        while(last->next != head)
            last = last -> next;
        last -> next = newNode;
    }
    return head;
}

// struct Node *enqueuePosition(struct Node *head, int position, int newData){
//     struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
//     newNode -> data = newData;
//     if(position == 1){
//         return enqueueFront(head,newData);
//     } else {
//         struct Node *current = head;
//         for(int i=1; i<position-1 && current!=head; i++)
//             current = current -> next;
//         if(current == head){
//             printf("\nINVALID POSITION\n");
//             free(newNode);
//             return head;
//         }
//         newNode -> next = current -> next;
//         current -> next = newNode;
//         return head;
//     }
// }

struct Node *dequeueFront(struct Node *head){
    if(head == NULL){
        printf("\nList is Empty!\n");
        return head;
    }
    else {
        struct Node *newHead = head -> next;
        if(head -> next == head){
            free(head);
            printf("\nSuccessfully deleted from Front\n");    
            head = NULL;
            return head;
        } 
        struct Node *last = head;
        while(last->next != head)
            last = last -> next;       
        last -> next = newHead;
        free(head);
        printf("\nSuccessfully deleted from Front\n");        
        return newHead;
    }
}

struct Node *dequeueRear(struct Node *head){
    if(head ==  NULL){
        printf("\nList Empty!\n");
        return head;
    } else {
        struct Node *last = head;
        struct Node *preLast = NULL;
        while(last -> next != head){
            preLast = last;
            last = last -> next;
        }
        if(preLast == NULL){
            free(head);
            head = NULL;
        } else {
            preLast -> next = head;
            free(last);
        }
    printf("\nSuccessfully deleted from Rear\n");
    return head;
    }
}

// struct Node *dequeuePosition(struct Node *head, int position) {
//     if (head == NULL) {
//         printf("\nList is Empty!\n");
//         return head;
//     }
//     if (position == 1) {
//         return dequeueFront(head);
//     }
//     struct Node *current = head;
//     struct Node *preCurrent = NULL;
//     int count = 1;
//     for(int i=0; i<position && current->next!= head; i++){
//         preCurrent = current;
//         current = current -> next;
//     }
//     if (current -> next == head) {
//         printf("\nInvalid Position\n");
//         return head;
//     }
//     preCurrent->next = current->next;
//     free(current);
//     printf("\nElement at Position %d Deleted!\n", position);
//     return head;
// }


struct Node *displayLinkedList(struct Node *head){
    if(head == NULL)
        printf("\nList Empty!\n");
    else {
        printf("\nCurrent list is: ");
        struct Node *last = head;
        do {
            printf("%d -> ", last->data);
            last = last -> next;
        } while(last != head);
        printf("HEAD -> %d\n", head -> data);
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
            default:
                printf("\nChoose a valid Operation!");
        }
    }
    return 0;
}