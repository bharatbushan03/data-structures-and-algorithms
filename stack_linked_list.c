#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;
Node* top=NULL;
Node* createNode(int val) {
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=val;
    newNode->next=NULL;
    return newNode;
}
void Push(int val) {
    Node* newNode=createNode(val);
    newNode->next=top;
    top=newNode;
    printf("Node Inserted!!!\n");
}
void Pop() {
    if (top==NULL) {
        printf("Stack Overflow!!!\n");
    }
    else {
        Node* temp=top;
        top=top->next;
        printf("Deleted Element is %d\n",temp->data);
        free(temp);
    }
}
void Peek() {
    if (top==NULL) printf("Stack is empty!!!\n");
    else printf("%d\n",top->data);
}
void Display() {
    Node* temp=top;
    while (temp!=NULL) {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main() {
    while (1) {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        int choice, val;
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                printf("Enter value : ");
                scanf("%d",&val);
                Push(val);
                break;
            case 2:
                Pop();
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
                printf("Invalid choice!!!\n");
        }
    }
    return 0;
}