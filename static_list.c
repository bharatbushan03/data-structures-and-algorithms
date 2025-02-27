#include <stdio.h>

#define MAX_SIZE 100

int list[MAX_SIZE];
int count = 0;

void insert(int value) {
    if (count < MAX_SIZE) {
        list[count++] = value;
    } else {
        printf("List is full.\n");
    }
}

void delete(int value) {
    for (int i = 0; i < count; i++) {
        if (list[i] == value) {
            for (int j = i; j < count - 1; j++) {
                list[j] = list[j + 1];
            }
            count--;
            return;
        }
    }
    printf("Value not found.\n");
}

void update(int old_value, int new_value) {
    for (int i = 0; i < count; i++) {
        if (list[i] == old_value) {
            list[i] = new_value;
            return;
        }
    }
    printf("Value not found.\n");
}

void traverse() {
    if (count == 0) {
        printf("List is empty.\n");
    } else {
        for (int i = 0; i < count; i++) {
            printf("%d ", list[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value, old_value, new_value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n2. Delete\n3. Update\n4. Traverse\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                delete(value);
                break;
            case 3:
                printf("Enter old value to update: ");
                scanf("%d", &old_value);
                printf("Enter new value: ");
                scanf("%d", &new_value);
                update(old_value, new_value);
                break;
            case 4:
                traverse();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
