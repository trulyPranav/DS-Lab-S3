#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char item){
    if(top>=MAX-1)
        printf("\nOverFlow Error!\n");
    else {
        top++;
        stack[top] = item;
    }
}

char pop(){
    if(top < 0)
        printf("\nUnderFlow Error!\n");
    else {
        return stack[top--];
    }
}

int isOperator(char ch){
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        return 1;
    else return 0;
}

int precedence(char ch){
    if(ch == '^')
        return 3;
    else if(ch == '*' || ch == '/')
        return 2;
    else if(ch == '+' || ch == '-')
        return 1;
    else return 0;
}

void infixToPostfix(char infix[], char postfix[]){
    int i=0,j=0;
    push('(');
    strcat(infix,")");
    char x, item = infix[i];
    while(item != '\0'){
        if(item == '(')
            push(item);
        else if(isdigit(item) || isalpha(item)){
            postfix[j] = item;
            j++;
        }
        else if(isOperator(item) == 1){
            x = pop();
            while(isOperator(x) == 1 && precedence(x) >= precedence(item)){
                postfix[j] = x;
                j++;
                x = pop();
            }
            push(x);
            push(item);
        }
        else if(item == ')'){
            x = pop();
            while(x != '('){
                postfix[j] = x;
                j++;
                x = pop();
            }
        }
        else {
            printf("Invalid Expression!");
            exit(1);
        }
        i++;
        item = infix[i];
    }
    postfix[j] = '\0';
}

int main(){
    char infix[MAX],postfix[MAX];
    printf("Enter the Infix Expression: ");
    scanf("%s", infix);
    infixToPostfix(infix,postfix);
    printf("PostFix Expression is: ");
    for(int i=0; postfix[i]!='\0'; i++)
        printf("%c", postfix[i]);
    return 0;
}