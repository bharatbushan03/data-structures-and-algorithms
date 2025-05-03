#include <stdio.h>
#define MAX 100
int tree[MAX];
void init() {
    for (int i = 0; i < MAX; i++) {
        tree[i] = -1;
    }
}
void insert(int val) {
    for (int i = 0; i < MAX; i++) {
        if (tree[i] == -1) {
            tree[i] = val;
            printf("Element Inserted\n");
            return;
        }
    }
    printf("Tree is full\n");
}
int search(int val) {
    for (int i = 0; i < MAX; i++) {
        if (tree[i] == val) {
            printf("Element found at index %d\n",i);
            return i;
        }
    }
    printf("Not found\n");
    return -1;
}
void delete(int val) {
    int idx = search(val);
    if (idx == -1) {
        printf("Value not found\n");
        return;
    }
    int lastIdx = -1;
    for (int i = MAX - 1; i >= 0; i--) {
        if (tree[i] != -1) {
            lastIdx = i;
            break;
        }
    }
    if (lastIdx != -1) {
        printf("Element deleted\n");
        tree[idx] = tree[lastIdx];
        tree[lastIdx] = -1;
    }
}
void inorder(int idx) {
    if (idx >= MAX || tree[idx] == -1) return;
    inorder(2 * idx + 1);
    printf("%d ", tree[idx]);
    inorder(2 * idx + 2);
}
void preorder(int idx) {
    if (idx >= MAX || tree[idx] == -1) return;
    printf("%d ", tree[idx]);
    preorder(2 * idx + 1);
    preorder(2 * idx + 2);
}
void postorder(int idx) {
    if (idx >= MAX || tree[idx] == -1) return;
    postorder(2 * idx + 1);
    postorder(2 * idx + 2);
    printf("%d ", tree[idx]);
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
                insert(val);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                delete(val);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &val);
                search(val);
                break;
            case 4:
                printf("Inorder Traversal: ");
                inorder(0);
                printf("\n");
                break;
            case 5:
                printf("Preorder Traversal: ");
                preorder(0);
                printf("\n");
                break;
            case 6:
                printf("Postorder Traversal: ");
                postorder(0);
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
