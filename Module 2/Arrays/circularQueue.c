/* **************************************************************CHECK AGAIN!!****************************************************** */

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
        printf("\nElement inserted successfully!");
    } else {
        rear = (rear+1)%MAX;
        cQ[rear] = input;
        printf("\nElement inserted successfully!");
    }
}

int dequeue(){
    if(isEmpty())
        printf("\nUnderFlow Error");
    else {
        return cQ[front];
        if(front == rear){
            front == rear = -1;
        else
            front = (front+1)%MAX;
    }  
    }      
}

void peek(){
    if(isEmpty())
        printf("Queue is Empty! Nothing to Peek!");
    else
        printf("Element currently at the front is %d", cQ[front]);
};

void display(){
    for(int i=front; i!=rear; )
}

int main(){
    return 0;
}