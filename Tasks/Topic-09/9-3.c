#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point {
    double x, y;
} Point;

typedef struct Stack {
    Point *array;
    int size;
} Stack;

void printPoint(Point p);
Point createPoint(double x, double y);
double getDistance(Point a, Point b);
void initStack(Stack *stack);
void printStack(Stack *stack);
int getStackSize(Stack *stack);
void push(Stack *stack, Point value);
Point top(Stack *stack);
Point pop(Stack *stack);
void destroyStack(Stack *stack);

int main() {
    Stack *stack = malloc(sizeof(Stack*)); 
    initStack(stack); 
    push(stack, createPoint(1, 1)); 
    push(stack, createPoint(2, -3)); 
    push(stack, createPoint(-5, 2)); 
    push(stack, createPoint(2.5, 2.5)); 
    push(stack, createPoint(1.24, 4.23));
    printStack(stack);

    return 0;
}

void printPoint(Point p) {
    printf("(%.2lf; %.2lf)", p.x, p.y);
}

Point createPoint(double x, double y) {
    Point ptr;
    ptr.x = x;
    ptr.y = y;

    return ptr;
}

double getDistance(Point a, Point b) {
    return sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2));
}

void destroyStack(Stack *stack) {
    free(stack->array);
    stack->size = 0;
}

Point pop(Stack *stack) {
    Point a = top(stack);
    stack->array = realloc(stack->array, --stack->size);

    return a;
}

Point top(Stack *stack) {
    if (stack->array != NULL) {
        return stack->array[stack->size - 1];
    } else {
        return createPoint(0, 0);
    }
}

void push(Stack *stack, Point value) {
    if (stack->size == 0) {
        stack->array = malloc(sizeof(Point));
        stack->array[0] = value;
        ++stack->size;
    } else {
        stack->array = realloc(stack->array, (++stack->size)*sizeof(Point));
        stack->array[stack->size - 1] = value;
    }
}

int getStackSize(Stack *stack) {
    return stack->size;
}

void printStack(Stack *stack) {
    if (stack->array != NULL) {
        for (int i = 0; i < stack->size; ++i) {
            printf("Distance from point ");
            printPoint(stack->array[i]);
            printf(" to the origin is %lf\n", getDistance(stack->array[i], createPoint(0, 0)));
        }
        printf("\n");
    }
}

void initStack(Stack *stack) {
    stack->array = NULL;
    stack->size = 0;
}