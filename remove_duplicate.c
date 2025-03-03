#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX 100
char stack[MAX],top=-1;
void push(char ch){
    stack[++top] = ch;
}
void pop(){
    if(top == -1) return;
    top--;
}

bool isFull(){
    return top == MAX - 1;
}
bool isEmpty(){
    return top == -1;
}
char peek(){
    if(top == -1) return '\0';
    return stack[top];
}
void show(){
  if(top == -1) return;
  char val = peek();
  pop();
  show();
  printf("%c",val);
}
int main(){
    char str[1000];
    scanf("%s",str);

    int n = strlen(str);
    for(int i=0;i<n;i++){
        char ch = str[i];
        if(isEmpty()) push(ch);
        else if(ch == peek()) pop();
        else{
            push(ch);
        }
    }
    show();
    return 0;
}