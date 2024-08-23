#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int stack[MAX];
int top = -1;

int isEmpty(){
    if(top == -1)
        return 0;
    else return 1;
};

int isFull(){
    if(top == (MAX-1))
        return 1;
    else return 0;
};

void push(int n){
    if(isFull() == 1)
        printf("\nOverFlow Error");
    else {
        top++;
        stack[top] = n;
        printf("\nElement Inserted Successfully!");
    }
};

int pop(){
    if(isEmpty() == 0){
        printf("\nUnderFlow Error");}
    else{
        return stack[top--];
    }
};

void peek(){
    if(isEmpty() == 0)
        printf("UnderFlow Error");
    else
        printf("\nLatest Element in the stack is %d", stack[top]);
};

void display(){
    if(top == -1)
        printf("\nUnderFlow Error");
    else {
        printf("Stack is: ");
        for(int i=0; i<=top; i++)
            printf("%d ", stack[i]);
    }
};


int main(){
    while(1){
        printf("\n\n1)Insert an Element\n2)Delete an Element\n3)Peek an Element\n4)Display Stack\n5)Check if Full/Empty\n6)Exit Program\n");
        int n;
        printf("Choose the operation to perform: ");        
        scanf("%d", &n);
        switch(n){
            case 1:
                printf("Enter the Element to insert: ");
                int e;
                scanf("%d", &e);
                push(e);
                break;
            case 2:
                if(isEmpty() == 0)
                    pop();
                else 
                    printf("\nElement Deleted Successfully. Deleted Element is %d", pop());
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                if(isEmpty() == 0)
                    printf("\nStack is Empty");
                else if(isFull() == 1)
                    printf("\nStack is Full");
                else
                    printf("Stack is neither full nor empty");
                break;
            case 6:
                exit(1);
                break;
            default:
                printf("Choose a valid option!");
        }
    }
}