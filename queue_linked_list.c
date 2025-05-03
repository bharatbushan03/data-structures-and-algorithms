#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;
Node* front=NULL;
Node* rear=NULL;
Node* createNode(int val) {
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=val;
    newNode->next=NULL;
    return newNode;
}
void Enqueue(int val) {
    Node* newNode=createNode(val);
    if (front==NULL) {
        front=rear=newNode;
    }
    else {
        rear->next=newNode;
        rear=newNode;
    }
    printf("Node Inserted!!\n");
}
void Dequeue() {
    if (front==NULL) printf("Queue Overflow!!!\n");
    else {
        Node* temp=front;
        front=front->next;
        printf("Deleted Element is %d\n",temp->data);
        free(temp);
    }
}
void Peek() {
    if (front==NULL) printf("Queue is empty!!!\n");
    else printf("%d\n",front->data);
}
void Display() {
    if (front==NULL) printf("Queue is empty!!!\n");
    else {
        Node* temp=front;
        while (temp!=NULL) {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}
int main() {
    while (1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        int choice, val;
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                printf("Enter val : ");
                scanf("%d",&val);
                Enqueue(val);
                break;
            case 2:
                Dequeue();
                break;
            case 3:
                Peek();
                break;
            case 4:
                Display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}