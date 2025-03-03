#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 100
int stack[MAX],top=-1;
void push(int val){
    if(top == MAX-1) return;
    else{
        stack[++top] = val;
    }
}
int pop(){
    if(top == -1) return -1;
    else return stack[top--];
}
void display(){
    if(top == -1) return;
    else{
        printf("%d ",stack[top--]);
    }
}
int main() {
    int val;
    for(int i=0;i<3;i++){
        scanf("%d",&val);
        push(val);
    }
    pop();
    for(int i=0;i<2;i++){
        scanf("%d",&val);
        push(val);
    }
    pop();
    pop();
    pop();
    display();
    return 0;
}
