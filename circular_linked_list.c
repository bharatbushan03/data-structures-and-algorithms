#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
}Node;
Node* head=NULL;
void InsertInBeg(int val) {
    Node* newNode=(Node*)malloc(sizeof(Node));
    if (newNode==NULL) {
        printf("List is full!!!\n");
        return;
    }
    newNode->data=val;
    newNode->next=head;
    Node* temp=head;
    while (temp->next!=head) {
        temp=temp->next;
    }    
    head=newNode;
    temp->next=head;
    printf("Node Inserted!!!\n");
}
void InsertInEnd(int val) {
    Node* newNode=(Node*)malloc(sizeof(Node));
    if (newNode==NULL) {
        printf("List is full!!!\n");
        return;
    }
    newNode->data=val;
    newNode->next=NULL;
    if (head==NULL) {
        head=newNode;
        head->next=head;
    }
    else {
        Node* temp=head;
        while (temp->next!=head) temp=temp->next;
        temp->next=newNode;
        newNode->next=head;
    }
    printf("Node Inserted!!!\n");
}
void InsertInPos(int pos, int val) {
    if (pos==1) {
        InsertInBeg(val);
        return;
    }
    Node* newNode=(Node*)malloc(sizeof(Node));
    if (newNode==NULL) {
        printf("List is full!!!\n");
        return;
    }
    newNode->data=val;
    int currpos=1;
    Node* temp=head;
    while (temp->next!=head && currpos<pos-1) {
        currpos++;
        temp=temp->next;
    }
    if (currpos<pos-1) {
        printf("Invalid position!!!\n");
        free(newNode);
        return;
    }
    newNode->next=temp->next;
    temp->next=newNode;
    printf("Node Inserted!!!\n");
}
void DeleteInBeg() {
    if (head==NULL) {
        printf("List is empty!!!\n");
        return;
    }
    Node* temp=head;
    printf("Deleted Node is %d\n",temp->data);
    if (head->next==head) {
        free(head);
        head=NULL;
    }
    else {
        Node* curr=head;
        while (curr->next!=head) curr=curr->next;
        head=head->next;
        curr->next=head;
        free(temp);
    }
}
void DeleteInEnd() {
    if (head==NULL) {
        printf("List is empty!!!\n");
        return;
    }
    Node* temp=head;
    Node* curr=NULL;
    while (temp->next!=NULL) {
        curr=temp;
        temp=temp->next;
    }
    printf("Deleted Node is %d\n",temp->data);
    if (curr==NULL) {
        free(temp);
        head=NULL;
    }
    else {
        curr->next=head;
        free(temp);
    }
}
void DeleteInPos(int pos) {
    if (pos<1) {
        printf("Invalid position!!!\n");
        return;
    }
    if (pos==1) {
        DeleteInBeg();
        return;
    }
    if (head==NULL) {
        printf("List is empty!!!\n");
        return;
    }
    int currpos=1;
    Node* temp=head;
    while (temp->next!=head && currpos<pos-1) {
        currpos++;
        temp=temp->next;
    }
    if (currpos!=pos-1) {
        printf("Invalid position!!!\n");
        return;
    }
    Node* curr=temp->next;
    temp->next=temp->next->next;
    printf("Delete Node is %d\n", curr->data);
    free(curr);
}
void Search(int val) {
    if (head->data==val) {
        printf("Element found!!!\n");
        return;
    }
    Node* temp=head->next;
    while (temp!=head) {
        if (temp->data==val) {
            printf("Element found!!!\n");
            return;
        }
        temp=temp->next;
    }

    printf("Element not found!!!\n");
}
int main() {
    while (1) {
        printf("1. Insert in Beginning\n");
        printf("2. Insert in End\n");
        printf("3. Insert in any position\n");
        printf("4. Delete in Beginning\n");
        printf("5. Delete in End\n");
        printf("6. Delete in any position\n");
        printf("7. Linear search\n");
        printf("8. Exit\n");
        int choice, val, pos;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value : ");
                scanf("%d", &val);
                InsertInBeg(val);
                break;
            case 2:
                printf("Enter value : ");
                scanf("%d", &val);
                InsertInBeg(val);
                break;
            case 3:
                printf("Enter position : ");
                scanf("%d",&pos);
                printf("Enter value : ");
                scanf("%d", &val);
                InsertInPos(pos,val);
                break;
            case 4:
                DeleteInBeg();
                break;
            case 5:
                DeleteInEnd();
                break;
            case 6:
                printf("Enter position : ");
                scanf("%d",&pos);
                DeleteInPos(pos);
                break;
            case 7:
                printf("Enter value : ");
                scanf("%d", &val);
                Search(val);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}