#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define MAX 100
int stack[MAX];
int top=-1;

void push(char ch){
    stack[++top] = ch;
}
void pop(){
    top--;
}
bool isEmpty(){
    return (top == -1);
}
int main(){
    char str[100];
    scanf("%[^\n]s",str);
    int n=strlen(str);
    for(int i=0;i<n;i++){
        char ch = str[i];
        if(ch == '(' || ch == '{' || ch == '['){
            push(ch);
        }
        else if(!isEmpty() && (ch == ')' || ch == '}' || ch == ']')){
            if(ch == ')' && stack[top] == '(') pop();
            if(ch == '}' && stack[top] == '{') pop();
            if(ch == ']' && stack[top] == '[') pop();
            else{
                printf("Not Valid\n");
                return 0;
            }
        }
        else{
            printf("Not Valid\n");
            return 0;
        }
    }
    if(isEmpty()) printf("Valid\n");
    else printf("Not Valid\n");
    return 0;
}