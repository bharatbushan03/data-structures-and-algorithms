#include<stdio.h>

void push(int* stack,int n,int* top,int val){
    stack[++(*top)] = val;
}
void display(int* stack,int top){
    for(int i=0;i<=top;i++) printf("%d ",stack[i]);
}
void sorting(int* stack,int top){
    for(int i=0;i<=top;i++){
        for(int j=i+1;j<=top;j++){
            if(stack[i] < stack[j]){
                //swapping
                int temp = stack[i];
                stack[i] = stack[j];
                stack[j] = temp;
            }
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int stack[n],top=-1;
    int val;
    for(int i=0;i<n;i++){
        scanf("%d",&val);
        push(stack,n,&top,val);
    }
    sorting(stack,top);
   
    display(stack,top);
    return 0;
}