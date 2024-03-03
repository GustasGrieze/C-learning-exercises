#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *elements;
    int size;
    int capacity;
} Stack;

void initStack(Stack *stack) {
    stack->elements = NULL;
    stack->size = 0;
    stack->capacity = 0;
}

void printStack(Stack *stack) {
    for (int i = 0; i < stack->size; i++) {
        printf("%d ", stack->elements[i]);
    }
    printf("\n");
}

int getStackSize(Stack *stack) {
    return stack->size;
}

void push(Stack *stack, int value) {
    if (stack->size == stack->capacity) {
        stack->capacity = stack->capacity == 0 ? 1 : stack->capacity * 2;
        stack->elements = realloc(stack->elements, stack->capacity * sizeof(int));
    }
    stack->elements[stack->size] = value;
    stack->size++;
}

int top(Stack *stack) {
    if (stack->size == 0) {
        return 0;
    }
    return stack->elements[stack->size - 1];
}

int pop(Stack *stack) {
    if (stack->size == 0) {
        return 0;
    }
    stack->size--;
    return stack->elements[stack->size];
}

void destroyStack(Stack *stack) {
    free(stack->elements);
    stack->elements = NULL;
    stack->size = 0;
    stack->capacity = 0;
}

int main() {
    Stack myStack;
    initStack(&myStack);
    push(&myStack, 10);
    push(&myStack, 20);

    printf("Stack size: %d\n", getStackSize(&myStack));
    printf("Top element: %d\n", top(&myStack));
    printStack(&myStack);

    printf("Popped element: %d\n", pop(&myStack));
    printStack(&myStack);

    destroyStack(&myStack);

    return 0;
}
