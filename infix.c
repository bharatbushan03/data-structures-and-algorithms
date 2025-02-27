#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
char operator[MAX];
int operand[MAX];
int top1=-1,top2=-1;
void pushoperator(char ch){
    operator[++top1] = ch;
}
void pushoperand(int a){
    operand[++top2] = a;
}
int popoperand(){
    return operand[top2--];
}
char popoperator(){
    return operator[top1--];
}

int preducence(char ch){
    if(ch == '+' || ch == '-') return 1;
    else if(ch == '*' || ch == '/') return 2;

    else return 0;
}

int apply(int b,int a,char ch){
    switch(ch){
        case '+' : return a+b;
        case '-' : return a-b;
        case '*' : return a*b;
        case '/' : return a/b;
    }

    return 0;
}
int evaluate(char *str){
    int i = 0;
    while(str[i] != '\0'){
        if(str[i] == ' '){
            i++;
            continue;
        }
        if(isdigit(str[i])){
            int num = 0;
            while(isdigit(str[i])){
                num = num * 10 + (str[i] - '0');
                i++;
            }
            pushoperand(num);
            i--;
        }
        else if(str[i] == '(') pushoperator(str[i]);
        else if(str[i] == ')'){
            while(top1 != -1 && operator[top1] != '('){
                int a = popoperand();
                int b = popoperand();
                char ch = popoperator();
                pushoperand(apply(a,b,ch));
            }
            popoperator();
        }

        else{
            while(top1 != -1 && preducence(operator[top1]) >= preducence(str[i])){
                int a = popoperand();
                int b = popoperand();
                char ch = popoperator();
                pushoperand(apply(a,b,ch));
            }
            pushoperator(str[i]);
        }

        i++;
    }

    while(top1 != -1){
        int a = popoperand();
        int b = popoperand();
        char ch = popoperator();
        pushoperand(apply(a,b,ch));
    }

    return popoperand();
}
int main(){
    char str[] = "(3 + 5) * 2 - 8 / 4";
    printf("Result: %d\n", evaluate(str));
    return 0;
}