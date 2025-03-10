#include <stdio.h>
#define MAX 100
int queue[MAX];
int front = -1,rear=-1;
int isEmpty(){
    return (front == -1);
}
int isFull(){
    return (rear == MAX - 1);
}
void enqueue(int val){
    rear++;
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
        front++;
    }

    return val;
}
int peek(){
    return queue[front];
}
void display(){
    printf("Queue elements are: ");
    for(int i=front;i<=rear;i++){
        printf("%d ",queue[i]);
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