#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define MAXSIZE 100

int stack[MAXSIZE];
int top = -1;

void push(int n){
    if(top == MAXSIZE-1)
        printf("OverFlow Error");
    else{
        top++;
        stack[top] = n;
    }
}
int pop(){
    if(top == -1)
        printf("UnderFlow Error");
    else{
        return stack[top--];
    }
}

int evaluate(char input[]){
    for(int i=0; input[i]!='\0'; i++){
        char ch = input[i];
        if(isdigit(ch)){
            push(ch-'0');
        }
        else if(ch == '*' || ch == '+' || ch == '-' || ch == '/' || ch == '^'){
            int b = pop();
            int a = pop();
            switch (ch)
            {
            case '+':
                push(a+b);
                break;
            
            case '-':
                push(a-b);
                break;
            case '*':
                push(a*b);
                break;
            case '/':
                push(a/b);
                break;
            case '^':
                push(pow(a,b));
            }
        }
    }
    return stack[top];
}

int main(){
    char input[20];
    printf("Enter the Postfix Expression: ");
    scanf("%s", input);
    int answer = evaluate(input);
    printf("Answer is %d", answer);
    return 0;
}
