#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point *elements;
    int size;
    int capacity;
} Stack;

Point createPoint(double x, double y) {
    Point p;
    p.x = x;
    p.y = y;
    return p;
}

double getDistance(Point a, Point b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

void initStack(Stack *stack) {
    stack->elements = NULL;
    stack->size = 0;
    stack->capacity = 0;
}

void push(Stack *stack, Point value) {
    if (stack->size == stack->capacity) {
        stack->capacity = stack->capacity == 0 ? 1 : stack->capacity * 2;
        stack->elements = realloc(stack->elements, stack->capacity * sizeof(Point));
    }
    stack->elements[stack->size] = value;
    stack->size++;
}

Point top(Stack *stack) {
    if (stack->size == 0) {
        return createPoint(0, 0);
    }
    return stack->elements[stack->size - 1];
}

Point pop(Stack *stack) {
    if (stack->size == 0) {
        return createPoint(0, 0);
    }
    stack->size--;
    return stack->elements[stack->size];
}

void printStack(Stack *stack) {
    for (int i = 0; i < stack->size; i++) {
        Point p = stack->elements[i];
        printf("Point (%lf, %lf), Distance from origin: %lf\n", p.x, p.y, getDistance(p, createPoint(0, 0)));
    }
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

    push(&myStack, createPoint(1.0, 2.0));
    push(&myStack, createPoint(3.0, 4.0));
    push(&myStack, createPoint(5.0, 6.0));
    push(&myStack, createPoint(7.0, 8.0));
    push(&myStack, createPoint(9.0, 10.0));

    printStack(&myStack);

    destroyStack(&myStack);

    return 0;
}
