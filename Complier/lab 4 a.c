#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;

void push(Stack *s, char value) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    s->items[++(s->top)] = value;
}

char pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->items[(s->top)--];
}

char peek(Stack *s) {
    return s->items[s->top];
}

bool is_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

void reverseString(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; ++i) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

void infixToPrefix(char *exp) {
    Stack stack;
    stack.top = -1;
    char prefix[MAX_SIZE];
    int j = 0;

    reverseString(exp);

    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == ' ')
            continue;
        else if (isdigit(exp[i]) || isalpha(exp[i]))
            prefix[j++] = exp[i];
        else if (is_operator(exp[i])) {
            while (stack.top != -1 && precedence(peek(&stack)) > precedence(exp[i])) {
                prefix[j++] = pop(&stack);
            }
            push(&stack, exp[i]);
        }
        else if (exp[i] == ')')
            push(&stack, exp[i]);
        else if (exp[i] == '(') {
            while (stack.top != -1 && peek(&stack) != ')') {
                prefix[j++] = pop(&stack);
            }
            pop(&stack); // Discard the ')'
        }
    }

    while (stack.top != -1) {
        prefix[j++] = pop(&stack);
    }
    prefix[j] = '\0';

    reverseString(prefix);

    printf("Prefix Expression: %s\n", prefix);
}

int main() {
    char exp[] = "a+(b-c)";
    infixToPrefix(exp);
    return 0;
}
