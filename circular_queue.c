#include <stdio.h>
#define MAX 5
int queue[MAX];
int front = -1,rear=-1;
int isEmpty(){
    return (front == -1) ? 1 : 0;
}
int isFull(){
    return (front == (rear+1)%MAX) ? 1 : 0;
}
void enqueue(int val){
    rear = (rear+1)%MAX;
    if(front == -1){
        front = rear;
    }
    queue[rear] = val;
}
int dequeue(){
    int val = queue[front];
    if(front == rear){
        front = rear = -1;
    }
    else{
        front = (front+1)%MAX;
    }

    return val;
}
int peek(){
    return queue[front];
}
void display(){
    int i=front;
    printf("Queue elements are : %d ",queue[i]);
    i = (i+1)%MAX;
    while(i != (rear+1)%MAX){
        printf("%d ",queue[i]);
        i = (i+1)%MAX;
    }
    printf("\n");
}
int main(){
    while(1){
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. display\n");
        printf("5. Exit\n");
        printf("Enter your choice : ");
        int choice,val;
        scanf("%d",&choice);
        switch(choice){
            case 1:
            if(isFull()){
                printf("Queue overflow!!!\n");
                }
            else{
                printf("Enter val to enqueue : ");
                scanf("%d",&val);
                enqueue(val);
                }
                break;
            case 2:
                if(isEmpty()){
                    printf("queue is empty\n");
                }
                else{
                    printf("dequeue element is %d\n",dequeue());
                }
                break;
            case 3:
                if(isEmpty()){
                    printf("queue is empty\n");
                    return -1;
                }
                else{
                    printf("peek element is %d\n",peek());
                }
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice !!!\n");
                break;
        }
    }
    return 0;
}