#include <stdio.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;
Node* head=NULL;
void Push(int val) {
    Node* newNode=(Node*)malloc(sizeof(Node*));
    if (newNode==NULL) {
        printf("Stack overflow!!!\n");
        return;
    }
    newNode->data=val;
    if (head==NULL) { 
        head=newNode;
    }
    else {
        newNode->next=head;
        head=newNode;
    }
    printf("Element Inserted!!!\n");
}
int Pop() {
    if (head==NULL) {
        return -1;
    }
    else {
        Node* temp=head;
        head=head->next;
        int val=temp->data;
        free(temp);
        return val;
    }
}
int Peek() {
    if (head==NULL) {
        return -1;
    }
    else {
        return head->data;
    }
}
void Show() {
    if (head==NULL) {
        printf("Stack overflow\n");
        return;
    }
    Node* temp=head;
    printf("Elements of stack are : ");
    while (temp!=NULL) {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
int main() {
    while (1) {
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEK\n");
        printf("4. SHOW\n");
        printf("5. EXIT\n");
        int choice,val;
        printf("Enter choice : ");
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                printf("Enter value : ");
                scanf("%d",&val);
                Push(val);
                break;
            case 2:
                val=Pop();
                if (val==-1) {
                    printf("Stack is empty!!!\n");
                }
                else {
                    printf("%d is poped\n",val);
                }
                break;
            case 3:
                val=Peek();
                if (val==-1) {
                    printf("Stack is empty\n");
                }
                else {
                    printf("%d is the Peek element\n");
                }
                break;
            case 4:
                Show();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid Choice!!!\n");
                break;
        }
    }
}