#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void infixToPostfix(char *exp) {
    Stack stack;
    stack.top = -1;
    char postfix[MAX_SIZE];
    int j = 0;

    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == ' ')
            continue;
        else if (isdigit(exp[i]) || isalpha(exp[i]))
            postfix[j++] = exp[i];
        else if (is_operator(exp[i])) {
            while (stack.top != -1 && precedence(peek(&stack)) >= precedence(exp[i])) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, exp[i]);
        }
        else if (exp[i] == '(')
            push(&stack, exp[i]);
        else if (exp[i] == ')') {
            while (stack.top != -1 && peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack); // Discard the '('
        }
    }

    while (stack.top != -1) {
        postfix[j++] = pop(&stack);
    }
    postfix[j] = '\0';

    printf("Postfix Expression: %s\n", postfix);
}

int main() {
    char exp[] = "a+(b-c)";
    infixToPostfix(exp);
    return 0;
}
