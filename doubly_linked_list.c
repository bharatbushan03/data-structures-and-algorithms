#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;
Node* head = NULL;
void InsertInBeg(int val) {
    Node* newNode=(Node*)malloc(sizeof(Node));
    if (newNode==NULL) {
        printf("List is full!!!\n");
        return;
    }
    newNode->data=val;
    newNode->next=head;
    newNode->prev=NULL;
    head->prev=newNode;
    head=newNode;
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
    newNode->prev=NULL;
    if (head==NULL) {
        head=newNode;
    }
    else {
        Node* temp=head;
        while (temp->next!=NULL) {
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->next=temp;
    }

    printf("Node Inserted!!!\n");
}
void InsertInPos(int pos,int val) {
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
    newNode->prev=newNode->next=NULL;
    int currpos=1;
    Node* temp=head;
    while (currpos<pos-1 && temp!=NULL) {
        currpos++;
        temp=temp->next;
    }

    if (temp==NULL) {
        printf("Invalid position!!!\n");
        free(newNode);
        return;
    }
    newNode->next=temp->next;
    if (temp->next!=NULL) {
        newNode->next->prev=newNode;
    }
    temp->next=newNode;
    newNode->prev=temp;
    printf("Node Inserted!!!\n");
}
void DeleteInBeg() {
    if (head==NULL) {
        printf("List is empty!!!\n");
        return;
    }
    Node* temp=head;
    head=head->next;
    printf("Deleted Node is %d\n",temp->data);
    free(head);
}
void DeleteInEnd() {
    if (head==NULL) {
        printf("List is empty!!!\n");
        return;
    }
    Node* temp=head;
    while (temp->next!=NULL) temp=temp->next;
    printf("Delete Node is %d\n",temp->data);
    free(temp);
}
void DeleteInPos(int pos) {
    if (head==NULL) {
        printf("List is empty!!!\n");
        return;
    }
    if (pos==1) {
        DeleteInBeg();
        return;
    }
    Node* temp=head;
    int currpos=1;
    while (temp!=NULL && currpos<pos-1) {
        currpos++;
        temp=temp->next;
    }
    if (temp==NULL || temp->next==NULL) {
        printf("Invalid position!!!\n");
        return;
    }
    Node* curr=temp->next;
    temp->next=temp->next->next;
    if (temp->next!=NULL) {
        temp->next->prev=temp;
    }
    printf("Deleted Node is %d\n",curr->data);
    free(curr);
}
void Search(int val) {
    Node* temp=head;
    while (temp!=NULL) {
        if (temp->data==val) {
            printf("Node found!!!\n");
            return;
        }
    }

    printf("Node not found!!!\n");
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