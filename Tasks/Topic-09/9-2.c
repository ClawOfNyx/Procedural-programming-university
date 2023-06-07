#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int *array;
    int size;
} Stack;

void initStack(Stack *stack);
void printStack(Stack *stack);
int getStackSize(Stack *stack);
void push(Stack *stack, int value);
int top(Stack *stack);
int pop(Stack *stack);
void destroyStack(Stack *stack);

int main() {
    Stack *stack = malloc(sizeof(Stack*));

    initStack(stack);
    push(stack, 2);
    printStack(stack);
    push(stack, -7);
    printf("Size = %d\n", getStackSize(stack));
    printf("Top value = %d\n", top(stack));
    push(stack, 3);
    printf("Popped: %d\n", pop(stack));
    printStack(stack);
    destroyStack(stack);
    printf("%d", top(stack));

    return 0;
}

void destroyStack(Stack *stack) {
    free(stack->array);
    stack->size = 0;
}

int pop(Stack *stack) {
    int a = top(stack);
    stack->array = realloc(stack->array, stack->size--);

    return a;
}

int top(Stack *stack) {
    if (stack->size > 0) {
        return stack->array[stack->size - 1];
    }

    return 0;
}

void push(Stack *stack, int value) {
    stack->size += 1;
    stack->array = realloc(stack->array, stack->size);
    stack->array[stack->size - 1] = value;
}

int getStackSize(Stack *stack) {
    return stack->size;
}

void printStack(Stack *stack) {
    for (int i = 0; i < stack->size; ++i) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

void initStack(Stack *stack) {
    stack->array = NULL;
    stack->size = 0;
}