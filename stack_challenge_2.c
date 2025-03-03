#include<stdio.h>
#define MAX 100
int stack[MAX],top = -1;
void push(int val){
    if(top < MAX-1) stack[++top] = val;
}

void pop(){
    if(top > -1) top--;
}
void display(){
    if(top > -1){
        for(int i=top;i>=0;i--) printf("%d ",stack[i]);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int val;
    for(int i=0;i<n;i++){
        scanf("%d",&val);
        push(val);
    }
   
    pop();
    pop();
    for(int i=0;i<4;i++){
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