#include <stdio.h>
#define MAX 100
int tree[MAX];
void init() {
    for (int i=0; i<MAX; i++) {
        tree[i]=-1;
    }
}
void Insert(int val,int root) {
    if (tree[root]==-1) {
        tree[root]=val;
        printf("Element Inserted!!!\n");
    }
    else if (tree[root]>val) {
        Insert(val,2*root+1);
    }
    else {
        Insert(val,2*root+2);
    }
}
int Search(int val,int root) {
    if (root>MAX || tree[root]==-1) {
        printf("Element Not Found!!!\n");
        return -1;
    }
    else if (tree[root]==val) {
        printf("Element Found\n");
        return root;
    }
    else if (tree[root]>val) {
        return Search(val,2*root+1);
    }
    else {
        return Search(val,2*root+2);
    }
}
void Preorder(int root) {
    if (root>MAX || tree[root]==-1) return;
    printf("%d ",tree[root]);
    Preorder(2*root+1);
    Preorder(2*root+2);
}
void Inorder(int root) {
    if (root>MAX || tree[root]==-1) return;
    Inorder(2*root+1);
    printf("%d ",tree[root]);
    Inorder(2*root+2);
}
void Postorder(int root) {
    if (root>MAX || tree[root]==-1) return;
    Postorder(2*root+1);
    Postorder(2*root+2);
    printf("%d ",tree[root]);
}
int FindMin(int root) {
    while (2*root+1<MAX && tree[2*root+1]!=-1) {
        root=2*root+1;
    }
    return root;
}
int FindMax(int root) {
    while (2*root+2<MAX && tree[2*root+2]!=-1) {
        root=2*root+2;
    }
    return root;
}
void Delete(int val,int root) {
    int idx=Search(val,root);
    if (idx==-1) {
        printf("Element Not Found!!!\n");
        return;
    }
    int left=2*root+1;
    int right=2*root+2;
    if ((left>=MAX || tree[left]==-1) && (right>=MAX || tree[right]==-1)) {
        tree[idx]=-1;
    }
    else if (left>=MAX || tree[left]==-1) {
        int mini=FindMin(right);
        tree[idx]=tree[mini];
        Delete(tree[mini],mini);
    }
    else{
        int maxi=FindMax(left);
        tree[idx]=tree[maxi];
        Delete(tree[maxi],maxi);
    }
}
int main() {
    int choice, val;
    init();
    while (1) {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                Insert(val,0);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                Delete(val,0);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &val);
                Search(val,0);
                break;
            case 4:
                printf("Inorder Traversal: ");
                Inorder(0);
                printf("\n");
                break;
            case 5:
                printf("Preorder Traversal: ");
                Preorder(0);
                printf("\n");
                break;
            case 6:
                printf("Postorder Traversal: ");
                Postorder(0);
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