#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isOperator(char ch) {
    char operators[] = "+-*/%=><&|^!~";
    for (int i = 0; i < strlen(operators); i++) {
        if (ch == operators[i])
            return true;
    }
    return false;
}

void classifyOperator(char ch) {
    char arithmetic[] = "+-*/%";
    char relational[] = "<>=";
    char logical[] = "&|^!";
    char bitwise[] = "&|^~";
    char assignment[] = "=";

    if (strchr(arithmetic, ch) != NULL)
        printf("%c is an arithmetic operator.\n", ch);
    else if (strchr(relational, ch) != NULL)
        printf("%c is a relational operator.\n", ch);
    else if (strchr(logical, ch) != NULL)
        printf("%c is a logical operator.\n", ch);
    else if (strchr(bitwise, ch) != NULL)
        printf("%c is a bitwise operator.\n", ch);
    else if (strchr(assignment, ch) != NULL)
        printf("%c is an assignment operator.\n", ch);
    else
        printf("%c is not a recognized operator.\n", ch);
}

int main() {
    char input[100];
    printf("Enter a string to analyze operators: ");
    fgets(input, sizeof(input), stdin);

    printf("\nOperators found:\n");
    for (int i = 0; i < strlen(input); i++) {
        if (isOperator(input[i])) {
            printf("%c ", input[i]);
            classifyOperator(input[i]);
        }
    }

    return 0;
}
