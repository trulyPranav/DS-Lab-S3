#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int dQ[MAX];
int front = -1;
int rear = -1;

int isEmpty(){
    if(front == -1 && rear == -1)
        return 1;
    return 0;
}

int isFull(){
    if((front == 0 && rear == MAX - 1) || (front == rear+1))
        return 1;
    return 0;
}

void enqueueFront(int input){
    if(isFull())
        printf("\nOverFlow Error!\n");
    else if(front == -1){
        front = 0;
        rear = 0;
    } else if(front == 0)
        front = MAX-1;
    else
        front--;
    dQ[front] = input;
}

void enqueueRear(int input){
    if(isFull()){
        printf("\nOverFlow Error\n");
    }
    else if(front == -1){
        front = 0;
        rear = 0;
    } else if(rear == MAX -1)
        rear = 0;
    else 
        rear++;
    dQ[rear] = input;
}

int dequeueFront(){
    if(isEmpty()){
        printf("\nQueue is Empty!\n");
        return -1;
    }
    int item = dQ[front];
    if(front == rear){
        front = -1;
        rear = -1;
    }
    else {
        if(front == MAX-1)
            front = 0;
        else 
            front++;
    }
    return item;
}

int dequeueRear(){
    if(isEmpty()){
        printf("\nQueue is Empty!\n");
        return -1;
    }
    int item = dQ[rear];
    if(front == rear){
        front = -1;
        rear = -1;
    }
    else {
        if(rear == 0)
            rear = MAX -1;
        else 
            rear--;
    }
    return item;
}

void display(){
    if(isEmpty()){
        printf("Queue is Empty!!");
        return;
    }
    printf("Queue is: ");
    int i = front;
    if(front <= rear){
        while(i<=rear)
            printf("%d ", dQ[i++]);
    } else {
        while(i<=MAX-1)
            printf("%d ", dQ[i++]);
        i=0;
        while(i<=rear)
            printf("%d ", dQ[i++]);                        
    }
}

int main(){
    printf("Welcome to Double Ended Queues!\n");
    while(1){
        printf("\nOperations:\n1)Enqueue from Front\n2)Enqueue from Rear\n3)Dequeue from Front\n4)Dequeue from Rear\n5)Display Queue\n6)EXIT\n");
        printf("Choose: ");
        int opr;
        scanf("%d", &opr);
        switch(opr){
            case 1:
                printf("Enter element to insert: ");
                int elm;
                scanf("%d", &elm);
                enqueueFront(elm);
                break;
            case 2:
                printf("Enter element to insert: ");
                int revElm;
                scanf("%d", &revElm);
                enqueueRear(revElm);
                break; 
            case 3:
                printf("Element removed from Queue is: %d", dequeueFront());
                break;
            case 4:
                printf("Element removed from Queue is: %d", dequeueRear());
                break;
            case 5:
                display();
                break;
            case 6:
                exit(1);
                break;
            default:
                printf("\nEnter Valid Operation!\n");                
        }
    }

}