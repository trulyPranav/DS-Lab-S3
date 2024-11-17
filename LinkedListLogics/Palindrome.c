#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node *next;
};

struct Node *head = NULL;

struct Node *insertRear(struct Node *head, char newData){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = newData;
    newNode -> next = NULL;
    if(head == NULL)
        head = newNode;
    else {
        struct Node *current = head;
        while(current->next != NULL)
            current = current -> next;
        current -> next = newNode;
    }
    return head;
}

int checkPalindrome(char word[]){
    int count = 0;
    for(int i=0; word[i] != '\0' ; i++){
        head = insertRear(head, word[i]);
        count++;
    }
    struct Node *front = head;
    for(int i=0; i< count/2; i++){
        struct Node *rear = head;
        for(int j=0; j<count-1-i; j++)
            rear = rear->next;
        if(front->data != rear->data)
            return 0;
        front = front->next;
    }
    return 1;
}


int main(){
    printf("Enter the Word: ");
    char word[100];
    scanf("%s", word);
    int result = checkPalindrome(word);
    if(result == 1)
        printf("\nPALINDROME\n");
    else 
        printf("\nNOT A PALINDROME\n");
    return 0;
}

