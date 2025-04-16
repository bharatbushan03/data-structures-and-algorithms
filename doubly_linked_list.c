#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;
Node* head = NULL;
void InsertNodeInBeg(int ele) {
    Node* newNode = (Node*)malloc(sizeof(Node)); 
    newNode->data = ele;
    if (head == NULL) {
        head=newNode;
    }
    else {
        newNode->next = head;
        head->prev=newNode;
        head = newNode;
    }
    printf("Element Inserted!!!\n");
}
void InsertNodeInEnd(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    if (head == NULL) {
        head=newNode;
    }
    else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev=temp;
    }
    printf("Element Insertes!!!\n");
}
void InsertAtPosition(int val,int pos) {
    if (pos == 1) {
        InsertNodeInBeg(val);
        return;
    }
    if (head == NULL) {
        printf("position is empty!!!\n");
    }
    int currpos=1;
    Node* temp = head;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = val;
    while (currpos < pos-1 && temp != NULL) {
        currpos++;
        temp = temp->next;
    }

    if (temp==NULL) return;
    newNode->next = temp->next;
    temp->next->prev=newNode;
    temp->next = newNode;
    newNode->prev=temp;
    printf("Element Inserted!!!!\n");
}
void DeleteNodeFromBeg() {
    if (head == NULL) {
        printf("List is empty!!!\n");
        return;
    }
    printf("Element to be deleted is %d!!!!\n",head->data);
    Node* temp = head;
    head = head->next;
    temp->next = NULL;
    free(temp);
}
void DeleteNodeFromEnd() {
    if (head == NULL) {
        printf("List is empty!!!!\n");
        return;
    }
    Node* temp = head;
    if (temp->next == NULL) {
        printf("Element to deleted is %d!!!\n",temp->data);
        free(temp);
        return;
    }
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    printf("Element to deleted is %d!!!\n",temp->next->data);
    Node* curr = temp->next;
    temp->next = NULL;
    free(curr);
    
}
void DeleteNodeFromPosition(int pos) {
    if (pos == 1) {
        DeleteNodeFromBeg(); 
        return; 
    } 
    if (head == NULL) { 
        printf("List is empty!!!\n"); 
        return; 
    } 
    Node* temp = head; 
    int currpos = 1; 
    while (currpos < pos-1 && temp != NULL) {
        currpos++;
        temp = temp->next;
    }
    Node* curr = temp->next;
    temp = temp->next->next;
    printf("Element to delete is %d\n",curr->data);
    free(curr);
}
bool Search(int val) {
    if (head == NULL) {
        return false;
    }
    Node* temp = head;
    while (temp != NULL && temp->data != val) {
        temp = temp->next;
    }

    if (temp == NULL) return false;
    return true;
}
void sort() {
    for (Node* i=head; i->next != NULL; i=i->next) {
        for (Node* j=head; j->next != NULL; j=j->next) {
            if (j->data > j->next->data) {
                int val=j->data;
                j->data=j->next->data;
                j->next->data=val;
            }
        }
    }
}

void display() {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ",temp->data);
        temp = temp->next; 
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
        printf("8. Sort Elements\n");
        printf("9. Display List\n");
        printf("10. Exit\n");
        int choice,val,pos;
        printf("Enter choice : ");
        scanf("%d",&choice);
        switch (choice) {
            case 1:
            printf("Enter the value : ");
            scanf("%d",&val);
            InsertNodeInBeg(val);
            break;
            case 2:
            printf("Enter the value : ");
            scanf("%d",&val);
            InsertNodeInEnd(val);
            break;
            case 3:
            printf("Enter element and pos : ");
            scanf("%d%d",&val,&pos);
            InsertAtPosition(val, pos);
            break;
            case 4:
            DeleteNodeFromBeg();
            break;
            case 5:
            DeleteNodeFromEnd();
            break;
            case 6:
            printf("Enter position : ");
            scanf("%d",&pos);
            DeleteNodeFromPosition(pos);
            break;
            case 7:
            printf("Enter value to search : ");
            scanf("%d",&val);
            if (Search(val)) printf ("Element found!!!!\n");
            else printf("Element not found!!!!\n");
            break;
            case 8:
            sort();
            display();
            break;
            case 9:
            display();
            break;
            case 10:
            return 0;
            break;
        }
    }
    return 0;
}                                                            