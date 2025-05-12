/*
Задание 1: Создать два стека для целых чисел. Первый стек – организовать ввод по возрастанию,
 второй стек – организовать ввод по возрастанию. Без сортировок и переворачивания
 исходных стеков сформировать третий стек упорядоченный по возрастанию
Задание 2: Создать два стека для целых чисел. Максимальные размеры стеков вводится с экрана.
Вывести из первого стека все элементы которых нет во втором стеке, учитывая порядок хранения в стеке.

Студент: Алейник И.С.
Дата: 11.05.2023
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "functions.h" 

int main() {
   

    int choice;

    do {
        printf("\nВыберите задание:\n");
        printf("1. Работа с тремя стеками (сортировка)\n");
        printf("2. Поиск уникальных элементов в стеках\n");
        printf("0. Выход\n");
        choice = getValidatedIntInput("Ваш выбор: ");

        switch (choice) {
            case 1: {
                Stack stack1, stack2, stack3;
                initStack(&stack1, MAX_SIZE);
                initStack(&stack2, MAX_SIZE);
                initStack(&stack3, MAX_SIZE);

                int value, numElements;

                printf("Введите количество элементов для первого стека: ");
                numElements = getValidatedIntInput("");

                printf("Введите элементы первого стека по возрастанию:\n");
                for (int i = 0; i < numElements; i++) {
                    value = correctChoice();
                    if (!isEmpty(&stack1) && value < stack1.data[stack1.top]) {
                        printf("Ошибка: число должно быть больше предыдущего!\n");
                        i--;
                    } else {
                        pushSorted(&stack3, value);
                        pushSorted(&stack1, value);
                    }
                }
                printStack(&stack1, "первого стека");

                printf("Введите количество элементов для второго стека: ");
                numElements = getValidatedIntInput("");

                printf("Введите элементы второго стека по возрастанию:\n");
                for (int i = 0; i < numElements; i++) {
                    value = correctChoice();
                    if (!isEmpty(&stack2) && value < stack2.data[stack2.top]) {
                        printf("Ошибка: число должно быть больше предыдущего!\n");
                        i--;
                    } else {
                        pushSorted(&stack3, value);
                        pushSorted(&stack2, value);
                    }
                }
                printStack(&stack2, "второго стека");

                printStack(&stack3, "третьего стека (упорядоченный по возрастанию)");

                freeStack(&stack1);
                freeStack(&stack2);
                freeStack(&stack3);
                break;
            }
            case 2: {
                Stack s1, s2;

                while (!initStack(&s1, getValidatedIntInput("Размер первого стека: "))) {
                    printf("Некорректный размер!\n");
                }

                while (!initStack(&s2, getValidatedIntInput("Размер второго стека: "))) {
                    printf("Некорректный размер!\n");
                }

                printf("Введите элементы первого стека:\n");
                while (!isFull(&s1)) {
                    push(&s1, getValidatedIntInput("> "));
                }

                printf("Введите элементы второго стека:\n");
                while (!isFull(&s2)) {
                    push(&s2, getValidatedIntInput("> "));
                }

                printf("\nСодержимое первого стека:\n");
                printStack(&s1, "первого стека");

                printf("\nСодержимое второго стека:\n");
                printStack(&s2, "второго стека");

                printf("\nУникальные элементы первого стека:\n");
                findAndPrintUniqueElements(&s1, &s2);

                freeStack(&s1);
                freeStack(&s2);
                break;
            }
            case 0:
                printf("Выход из программы.\n");
                break;
            default:
                printf("Некорректный выбор. Пожалуйста, повторите.\n");
        }
    } while (choice != 0);

    return 0;
}
