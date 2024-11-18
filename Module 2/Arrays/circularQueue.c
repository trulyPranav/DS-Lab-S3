#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int cQ[MAX];
int front = -1;
int rear = -1;

int isEmpty(){
    if(front == -1 && rear == -1)
        return 1;
    return 0;
}


int isFull(){
    if((rear+1)%MAX == front)
        return 1;
    return 0;
}

void enqueue(int input){
    if(isFull())
        printf("\nOverFlow Error");
    else if(front == -1 && rear == -1){
        front = 0;
        rear = 0;
        cQ[rear] = input;
        printf("\nElement inserted successfully!\n");
    } else {
        rear = (rear+1)%MAX;
        cQ[rear] = input;
        printf("\nElement inserted successfully!\n");
    }
}

int dequeue(){
    if(isEmpty())
        printf("\nUnderFlow Error");
    else {
        int item = cQ[front];
        if(front == rear)
            front = rear = -1;
        else
            front = (front+1)%MAX;
        return item;
    }      
}

void peek(){
    if(isEmpty())
        printf("Queue is Empty! Nothing to Peek!");
    else
        printf("Element currently at the front is %d", cQ[front]);
};

void display(){
    if(isEmpty())
        printf("\nQueue is Empty!\n");
    else {
        printf("Queue is: ");
        if(front == rear)
            printf("%d ", cQ[front]);
        else {
            for(int i= front; i!=rear; i = (i+1)%MAX)
                printf("%d ", cQ[i]);
            printf("%d ", cQ[rear]);
            printf("\n\n");
        }
    }
}

int main(){
    printf("Welcome to Circular Queues!\n");
    while(1){
        printf("\nOperations:\n1)Enqueue\n2)Dequeue\n3)Peek\n4)Display Queue\n5)EXIT\n");
        printf("Choose: ");
        int opr;
        scanf("%d", &opr);
        switch(opr){
            case 1:
                printf("Enter element to insert: ");
                int elm;
                scanf("%d", &elm);
                enqueue(elm);
                break;
            case 2:
                printf("Element removed from Queue is: %d", dequeue());
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(1);
                break;
            default:
                printf("\nEnter Valid Operation!\n");                
        }
    }
    return 0;    
}