#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Общие функции
int getValidatedIntInput(const char *prompt) {
    int value;
    char term;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d%c", &value, &term) == 2 && term == '\n' && value >= 0) {
            return value;
        }
        while (getchar() != '\n');
        printf("Ошибка ввода. Требуется целое неотрицательное число.\n");
    }
}

bool initStack(Stack *stack, int capacity) {
    if (capacity <= 0) return false;
    stack->data = (int *)malloc(capacity * sizeof(int));
    if (!stack->data) return false;
    stack->capacity = capacity;
    stack->top = -1;
    return true;
}

void freeStack(Stack *stack) {
    free(stack->data);
    stack->data = NULL;
    stack->capacity = 0;
    stack->top = -1;
}

bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

bool isFull(Stack *stack) {
    return stack->top == stack->capacity - 1;
}

void printStack(Stack *stack, const char *stackName) {
    printf("Содержимое %s (сверху вниз):\n", stackName);
    if (isEmpty(stack)) {
        printf("Стек пуст.\n");
        return;
    }
    for (int i = stack->top; i >= 0; i--) {
        printf("%d\n", stack->data[i]);
    }
    printf("\n");
}

// Функции для Задания 1
void pushSorted(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Ошибка: стек переполнен!\n");
        return;
    }

    int i = stack->top;
    while (i >= 0 && stack->data[i] > value) {
        stack->data[i + 1] = stack->data[i];
        i--;
    }

    stack->data[i + 1] = value;
    stack->top++;
}

int correctChoice() {
    return getValidatedIntInput("Введите число: ");
}

// Функции для Задания 2
bool push(Stack *stack, int value) {
    if (isFull(stack)) return false;
    stack->data[++stack->top] = value;
    return true;
}

int pop(Stack *stack) {
    return isEmpty(stack) ? EMPTY_STACK_VALUE : stack->data[stack->top--];
}

void findAndPrintUniqueElements(Stack *stack1, Stack *stack2) {
    Stack temp;
    if (!initStack(&temp, stack1->capacity)) return;

    while (!isEmpty(stack1)) {
        int val = pop(stack1);
        bool found = false;
        for (int i = 0; i <= stack2->top; i++) {
            if (stack2->data[i] == val) {
                found = true;
                break;
            }
        }
        if (!found) push(&temp, val);
    }

    while (!isEmpty(&temp)) {
        int val = pop(&temp);
        printf("%d\n", val);
        push(stack1, val);
    }
    freeStack(&temp);
}
