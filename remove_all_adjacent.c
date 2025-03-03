#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 100
char stack[MAX],top = -1;
void push(char ch){
    if(top == -1) stack[++top] = ch;
    else if(stack[top] == ch) pop();
    else stack[++top] = ch;
}

void pop(){
    if(top == -1) return;
    else top--;
}
void display(){
    for(int i=0;i<=top;i++) printf("%c",stack[i]);
}
int main() {
    char s[100];
    scanf("%s",s);
    for(int i=0;i<strlen(s);i++){
        push(s[i]);
    }
   
    display();
    return 0;
}

