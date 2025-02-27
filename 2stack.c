#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

int arr[MAX_SIZE], top1 = -1, top2 = MAX_SIZE;

void push1(int value){
    if(top1<top2-1){
        arr[++top1] = value;
        printf("%d pushed to stack 1\n", value);
    } else {
        printf("Stack 1 Overflow\n");
    }
}

void push2(int value) {
    if (top1 < top2 - 1) {
        arr[--top2] = value;
        printf("%d pushed to stack 2\n", value);
    } else {
        printf("Stack 2 Overflow\n");
    }
}

void pop1() {
    if (top1 == -1) {
        printf("Stack 1 Underflow\n");
    } else {
        printf("%d popped from stack 1\n", arr[top1--]);
    }
}

void pop2() {
    if (top2 == MAX_SIZE) {
        printf("Stack 2 Underflow\n");
    } else {
        printf("%d popped from stack 2\n", arr[top2++]);
    }
}

void peek1() {
    if (top1 == -1) {
        printf("Stack 1 is empty\n");
    } else {
        printf("Top element of stack 1 is %d\n", arr[top1]);
    }
}

void peek2() {
    if (top2 == MAX_SIZE) {
        printf("Stack 2 is empty\n");
    } else {
        printf("Top element of stack 2 is %d\n", arr[top2]);
    }
}

int isEmpty1() {
    return top1 == -1;
}

int isEmpty2() {
    return top2 == MAX_SIZE;
}

void display1() {
    if (top1 == -1) {
        printf("Stack 1 is empty\n");
    } else {
        printf("Stack 1 elements: ");
        for (int i = 0; i <= top1; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

void display2() {
    if (top2 == MAX_SIZE) {
        printf("Stack 2 is empty\n");
    } else {
        printf("Stack 2 elements: ");
        for (int i = MAX_SIZE - 1; i >= top2; i--) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push to Stack 1\n");
        printf("2. Push to Stack 2\n");
        printf("3. Pop from Stack 1\n");
        printf("4. Pop from Stack 2\n");
        printf("5. Peek Stack 1\n");
        printf("6. Peek Stack 2\n");
        printf("7. Display Stack 1\n");
        printf("8. Display Stack 2\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push to Stack 1: ");
                scanf("%d", &value);
                push1(value);
                break;
            case 2:
                printf("Enter value to push to Stack 2: ");
                scanf("%d", &value);
                push2(value);
                break;
            case 3:
                pop1();
                break;
            case 4:
                pop2();
                break;
            case 5:
                peek1();
                break;
            case 6:
                peek2();
                break;
            case 7:
                display1();
                break;
            case 8:
                display2();
                break;
            case 9:
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
