#include <stdio.h>
#include <stdlib.h>

int stack[10];
int top = -1;

int isEmpty();
int isFull();
void push();
int pop();
void peek();
void display();


int main(){
    while(1){
        printf("\n1)Insert an Element\n2)Delete an Element\n3)Peek an Element\n4)Display Stack\n5)Check if Full/Empty\n6)Exit Program\n");
        int n;
        printf("Choose the operation to perform: ");        
        scanf("%d", &n);
        switch(1){
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
        }
    }
}