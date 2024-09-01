#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int queue[MAX];
int front = -1;
int rear = -1;

int isEmpty(){
    if(front == -1 && rear == -1)
        return 1;
    else return 0;
}

int isFull(){
    if(rear == MAX-1)
        return 1;
    else return 0;
}

void enqueue(int input){
    if(isFull())
        printf("\nOverFlow Error");
    else if(front == -1 && rear == -1){
        front = 0;
        rear = 0;
        queue[rear] = input;
        printf("\nElement inserted successfully!");
    }
    else{
        rear++;
        queue[rear] == input;
        printf("\nElement inserted successfully!");        
    }
}

int dequeue(){
    if(isEmpty())
        printf("\nUnderFlow Error");
    else return queue[front++];
}

void peek(){
    printf("\nElement Currently at the front is: %d", queue[front]);
}

void display(){
    printf("\nElements of the Queue are: ");
    for(int i=front; i<=rear; i++)
        printf("%d ", queue[i]);
}

int main(){
        printf("\nWelcome to Basic Queue! The queue is currently empty. Do any of the operations below to get started:\n");
    while(1){
        printf("\n\n1)Insert an Element into the Queue.\n2)Delete an Element from the Queue.\n3)Peek latest Element.\n4)Display the Queue.\n5)Exit the program.");
        printf("\nEnter the operation to perform: ");  
        int n;
        scanf("%d", &n);
        switch(n){
            case 1:
                printf("\nEnter the Element to be inserted: ");
                int e;
                scanf("%d", &e);
                enqueue(e);
                break;
            case 2:
                if(isEmpty())
                    dequeue();
                else printf("Element deleted successfully. Deleted Element is: %d", dequeue());
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(1);
            default:
                printf("Enter a valid option!");
        }
    }
    return 0;
}