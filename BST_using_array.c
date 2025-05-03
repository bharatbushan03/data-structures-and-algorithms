#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int tree[MAX];
void init() {
    for (int i=0; i<MAX; i++) {
        tree[i]=-1;
    }
}
void Insert(int val,int i) {
    if (tree[i]==-1) {
        tree[i]=val;
        printf("Element Inserted!!!\n");
    }
    else if (tree[i]>val) {
        Insert(val,2*i+1);
    }
    else {
        Insert(val,2*i+2);
    }
}
int Search(int val) {
    for (int i=0; i<MAX; ) {
        if (tree[i]==val) {
            printf("Element found\n");
            return i;
        }
        else if (tree[i]>val) i=2*i+1;
        else i=2*i+2;
    }
    return -1;
}
void Delete(int val,int root) {
    int idx=Search(val);
    if (idx==-1) {
        printf("Element not found!!!\n");
        return;
    }
    if ((2*idx+1>=MAX || tree[2*idx+1]==-1) && (2*idx+2>=MAX || tree[2*idx+2]==-1)) {
        tree[idx]=-1;
    }
    else if (2*idx+1>=MAX || tree[2*idx+1]==-1) {
        int data=FindMin(2*idx+2);
        tree[idx]=tree[data];
        Delete(tree[data],2*idx+2);
    }
}
void Inorder(int idx) {
    if (idx >= MAX || tree[idx] == -1) return;
    Inorder(2 * idx + 1);
    printf("%d ", tree[idx]);
    Inorder(2 * idx + 2);
}
void Preorder(int idx) {
    if (idx >= MAX || tree[idx] == -1) return;
    printf("%d ", tree[idx]);
    Preorder(2 * idx + 1);
    Preorder(2 * idx + 2);
}
void Postorder(int idx) {
    if (idx >= MAX || tree[idx] == -1) return;
    Postorder(2 * idx + 1);
    Postorder(2 * idx + 2);
    printf("%d ", tree[idx]);
}
int main() {
    init();
    while (1) {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Preorder\n");
        printf("5. Inorder\n");
        printf("6. Postorder\n");
        printf("7. Exit\n");
        int choice, val;
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                printf("Enter value : ");
                scanf("%d",&val);
                Insert(val, 0);
                break;
            case 2:
                printf("Enter value : ");
                scanf("%d",&val);
                Delete(val,0);
                break;
            case 3:
                printf("Enter value : ");
                scanf("%d",&val);
                Search(val);
                break;
            case 4:
                printf("Preorder : ");
                Preorder(0);
                printf("\n");
                break;
            case 5:
                printf("Inorder : ");
                Inorder(0);
                printf("\n");
                break;
            case 6:
                printf("Postorder : ");
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