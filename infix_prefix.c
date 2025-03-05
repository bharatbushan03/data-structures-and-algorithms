#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int precedence(char ch){
    if(ch == '+' || ch == '-') return 1;
    else if(ch == '*' || ch == '/') return 2;
    else if(ch == '^') return 3;
    return 0;
}

char* evaluate(char* str){
    int n = strlen(str);
    char* s = (char*)malloc(n+1);
    int i=0,k=0;
    char stack[100];
    int top = -1;

    for(i=0;i<n;i++){
        char ch = str[i];

        if(ch == '('){
            stack[++top] = ch;
        }
        else if(isalnum(ch)){
            s[k++] = ch;
        }
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^'){
            while(top != -1 && precedence(ch) <= precedence(stack[top])){
                s[k++] = stack[top--];
            }
            stack[++top] = ch;
        }
        else if(ch == ')'){
            while(top != -1 && stack[top] != '('){
                s[k++] = stack[top--];
            }
            top--;
        }
    }

    while(top != -1){
        s[k++] = stack[top--];
    }
    s[i] = '\0';
    return s;
}

int main(){
    char str[] = "a+b*c";

    printf("%s",evaluate(str));

    return 0;
}