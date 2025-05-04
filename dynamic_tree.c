#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;
Node* createNode(int val) {
    Node* temp=(Node*)malloc(sizeof(Node));
    temp->data=val;
    temp->left=temp->right=NULL;
    return temp;
}
Node* Insert(Node* root,int val) {
    Node* newNode=createNode(val);
    if (root==NULL) return newNode;
    else if (root->data>val) {
        root->left=Insert(root->left,val);
    }
    else {
        root->right=Insert(root->right,val);
    }
    return root;
}
void Search(Node* root,int val) {
    if (root==NULL) {
        printf("Element Not Found!!!\n");
        return;
    }
    if (root->data==val) {
        printf("Element Found!!!\n");
    }
    else if (root->data>val){
        Search(root->left,val);
    }
    else {
        Search(root->right,val);
    }
}
Node* FindMin(Node* root) {
    if (root->left==NULL) return root;
    else return FindMin(root->left);
}
Node* Delete(Node* root,int val) {
    if (root==NULL) {
        printf("Element Not Found!!!\n");
        return NULL;
    }
    else if (root->data>val){
        root->left=Delete(root->left,val);
        return root;
    }
    else if (root->data<val){
        root->right=Delete(root->right,val);
        return root;
    }
    else {
        if (root->left==NULL && root->right==NULL) {
            free(root);
            return NULL;
        }
        else if (root->left==NULL) {
            Node* temp=root->right;
            free(root);
            return temp;
        }
        else if (root->right==NULL) {
            Node* temp=root->left;
            free(root);
            return temp;
        }
        else {
            Node* temp=FindMin(root->right);
            root->data=temp->data;
            Delete(root->right,temp->data);
            return root;
        }
    }
}
void Preorder(Node* root) {
    if (root==NULL) return;
    printf("%d ",root->data);
    Preorder(root->left);
    Preorder(root->right);
}
void Inorder(Node* root) {
    if (root==NULL) return;
    Inorder(root->left);
    printf("%d ",root->data);
    Inorder(root->right);
}
void Postorder(Node* root) {
    if (root==NULL) return;
    Postorder(root->left);
    Postorder(root->right);
    printf("%d ",root->data);
}
int main() {
    Node* root=NULL;
    while (1) {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        int choice, val;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                root=Insert(root,val);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                root=Delete(root,val);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &val);
                Search(root,val);
                break;
            case 4:
                printf("Inorder Traversal: ");
                Inorder(root);
                printf("\n");
                break;
            case 5:
                printf("Preorder Traversal: ");
                Preorder(root);
                printf("\n");
                break;
            case 6:
                printf("Postorder Traversal: ");
                Postorder(root);
                printf("\n");
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}