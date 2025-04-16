#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;
Node* head=NULL;
Node* tail=NULL;
void InsertAtBeg(int val) {
    Node* newNode=(Node*)malloc(sizeof(Node*));
    newNode->data=val;
    if (head==NULL) {
        head=tail=newNode;
        printf("Element Inserted!!!!\n");
        return;
    }
    newNode->next=head;
    head=newNode;
    tail->next=head;
    printf("Element Inserted!!!!\n");
}
void InsertAtEnd(int val) {
    Node* newNode=(Node*)malloc(sizeof(Node*));
    newNode->data=val;
    newNode->next=NULL;
    if (head==NULL) {
        head=tail=newNode;
        printf("Element Inserted!!!!\n");
        return;
    }
    tail->next=newNode;
    newNode->next=head;
    tail=newNode;
}
void InsertAtPos(int pos) {
    Node* temp=head;
    int currpos=0;
    while (temp!=head && currpos < pos-1) {
        temp=temp->next;
        currpos++;
    }
    if (temp==head) {
        printf("Invalid Position!!!\n");
        return;
    }
    int val;
    printf("Enter val : ");
    scanf("%d",&val);
    Node* newNode=(Node*)malloc(sizeof(Node*));
    newNode->data=val;
    newNode->next=NULL;
    newNode->next=temp->next;
    temp->next=newNode;
    printf("Element Inserted!!!\n");
}
void DeleteAtBeg() {
    Node* temp=head;
    if (head==NULL) {
        printf("List is empty!!!\n");
        return;
    }
    if (head->next==NULL) {
        free(head);
        head=NULL;
        tail=NULL;
        printf("Element Deleted!!!\n");
        return;
    }
    head=head->next;
    tail->next=head;
    free(temp);
    printf("Element Deleted!!!\n");
}
void DeleteAtEnd() {
    Node* temp=head;
    if (tail==NULL) {
        printf("List is empty!!!\n");
        return;
    }
    if (tail->next!=NULL) {
        free(tail);
        head=tail=NULL;
        printf("Element Deleted!!!\n");
        return;
    }
    while (temp->next->next!=head) {
        temp=temp->next;
    }
    free(tail);
    tail=temp;
    temp->next=head;
    printf("Element deleted!!!\n");
    return;    
}
void DeleteAtPos(int pos) {
    Node* temp=head;
    int currpos=0;
    while (temp!=head && currpos<pos-1) {
        currpos++;
        temp=temp->next;
    }
    if (temp==head) {
        printf("Invalid Position!!!\n");
        return;
    }
    Node* currnode=temp->next;
    currnode->next=temp->next->next;
    printf("Element Deleted!!!\n");
}
void Search(int val) {
    Node* temp=head;
    if (temp->data==val) {
        printf("Element found!!!\n");
    }
    temp=temp->next;
    while (temp!=head) {
        if (temp->data==val) {
            printf("Element Found!!!\n");
        }
        temp=temp->next;
    }

    printf("Element Not Found!!!\n");
}
void Display() {
    if (head==NULL) return;
    Node* temp=head;
    printf("%d ",temp->data);
    temp=temp->next;
    while (temp!=head) {
        printf("%d ",temp->data);
    }
    printf("\n");
}
int main() {
    while (1) {
        printf("1. Insert Node in Begining\n");
        printf("2. Insert Node in End\n");
        printf("3. Insert Node at any Position\n");
        printf("4. Delete Node from Begining\n");
        printf("5. Delete Node from End\n");
        printf("6. Delete Node from any Position\n");
        printf("7. Search Element in List\n");
        printf("8. Display List\n");
        printf("9. Exit\n");
        int choice ,val, pos;
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                printf("Enter val : ");
                scanf("%d",&val);
                InsertAtBeg(val);
                break;
            case 2:
                printf("Enter val : ");
                scanf("%d",&val);
                InsertAtEnd(val);
                break;
            case 3:
                printf("Enter position");
                scanf("%d",&pos);
                InsertAtPos(pos);
                break;
            case 4:
                DeleteAtBeg();
                break;
            case 5:
                DeleteAtEnd();
                break;
            case 6:
                printf("Enter position : ");
                scanf("%d",&pos);
                DeleteAtPos(pos);
                break;
            case 7:
                printf("Enter val : ");
                scanf("%d",&val);
                Search(val);
                break;
            case 8:
                Display();
                break;
            case 9:
            return 0;
                break;
        }
    }

    return 0;
}