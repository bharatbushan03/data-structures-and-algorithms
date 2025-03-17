#include <stdio.h>
#define SIZE 100
typedef struct PriorityQueue {
    int element;
    int priority;
} PQueue;
PQueue pq[SIZE];
int front=-1, rear=-1;
int isEmpty(){
    return (front == -1);
}
int isFull(){
    return (rear == SIZE - 1);
}
void enqueue(int val,int priority){
    rear = rear+1;
    pq[rear].element = val;
    pq[rear].priority = priority;
    if(front == -1) front = rear;
    printf("Element inserted\n");
}
int getHigherPriorityElement() {
    int highestPriorityIdx = front;
    for (int i = front + 1; i <= rear; i++) {
        if (pq[i].priority > pq[highestPriorityIdx].priority) {
            highestPriorityIdx = i;
        }
    }
    return highestPriorityIdx;
}
int dequeue() {
    int idx = getHigherPriorityElement();
    int data = pq[idx].element;
    if (idx == front && idx == rear) {
        front = rear = -1;
    }
    else if (idx == front) {
        front++;
    }
    else {
        for (int i=idx; i<rear; i++) {
            pq[i] = pq[i+1];
        }
        rear--;
    }

    return data;
}
int peek(){
    int idx = getHigherPriorityElement();
    return pq[idx].element;
}
void display(){
    printf("Elements of Priority Queue are :\n");
    for (int i=front; i<=rear; i++) {
        printf("Element : %d => Priority : %d\n",pq[i].element,pq[i].priority);
    }

    printf("\n");
}
int main() {
    while(1){
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice : ");
        int choice,val,p;
        scanf("%d",&choice);
        switch(choice){
            case 1:
            if(isFull()){
                printf("Queue overflow!!!\n");
                }
            else{
                printf("Enter val to enqueue : ");
                scanf("%d",&val);
                printf("Enter Priority ");
                scanf("%d",&p);
                enqueue(val,p);
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