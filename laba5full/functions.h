#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdbool.h>
#include <limits.h>

#define EMPTY_STACK_VALUE INT_MIN
#define MAX_SIZE 100 // Можно определить и в .c, если не нужен в main.c

typedef struct {
    int *data;
    int capacity;
    int top;
} Stack;

// Общие функции
int getValidatedIntInput(const char *prompt);
bool initStack(Stack *stack, int capacity);
void freeStack(Stack *stack);
bool isEmpty(Stack *stack);
bool isFull(Stack *stack);
void printStack(Stack *stack, const char *stackName);

// Функции для Задания 1
void pushSorted(Stack *stack, int value);
int correctChoice();

// Функции для Задания 2
bool push(Stack *stack, int value);
int pop(Stack *stack);
void findAndPrintUniqueElements(Stack *stack1, Stack *stack2);

#endif

