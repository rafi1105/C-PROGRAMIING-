#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a string is a keyword
int isKeyword(char *str) {
    char keywords[32][10] = {
        "auto", "break", "case", "char", "const", "continue", "default", "do",
        "double", "else", "enum", "extern", "float", "for", "goto", "if",
        "int", "long", "register", "return", "short", "signed", "sizeof", "static",
        "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
    };
    int i;
    for(i = 0; i < 32; ++i) {
        if(strcmp(keywords[i], str) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a string is an identifier
int isIdentifier(char *str) {
    if(!isalpha(str[0]) && str[0] != '_') {
        return 0;
    }
    int i;
    for(i = 1; i < strlen(str); ++i) {
        if(!isalnum(str[i]) && str[i] != '_') {
            return 0;
        }
    }
    return 1;
}

// Function to check if a string is a constant
int isConstant(char *str) {
    int i = 0;
    if (str[0] == '-' || str[0] == '+') // Handles sign if present
        i++;
    while (str[i]) {
        if (!isdigit(str[i])) // Check if every character is a digit
            return 0;
        i++;
    }
    return 1;
}

// Function to remove comments from a given input source program
void removeComments(FILE *inputFile, FILE *outputFile) {
    int prevChar = fgetc(inputFile);
    int currentChar = fgetc(inputFile);

    while (currentChar != EOF) {
        if (prevChar == '/' && currentChar == '/') {
            while (currentChar != '\n' && currentChar != EOF) {
                currentChar = fgetc(inputFile);
            }
            fprintf(outputFile, "\n");
        } else if (prevChar == '/' && currentChar == '*') {
            while (1) {
                prevChar = currentChar;
                currentChar = fgetc(inputFile);
                if (prevChar == '*' && currentChar == '/') {
                    break;
                }
            }
        } else {
            fputc(prevChar, outputFile);
        }

        prevChar = currentChar;
        currentChar = fgetc(inputFile);
    }

    // Write the last character if not EOF
    if (prevChar != EOF) {
        fputc(prevChar, outputFile);
    }
}

int main() {
    FILE *inputFile, *outputFile;
    char filename[100];
    char word[100];

    printf("Enter the filename to read: ");
    scanf("%s", filename);

    inputFile = fopen(filename, "r");
    if (inputFile == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Create a temporary file to store the source code without comments
    outputFile = fopen("temp.txt", "w");
    if (outputFile == NULL) {
        printf("Error creating temporary file.\n");
        fclose(inputFile);
        return 1;
    }

    removeComments(inputFile, outputFile);

    fclose(inputFile);
    fclose(outputFile);

    // Open the temporary file to read after comments removal
    inputFile = fopen("temp.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening temporary file.\n");
        return 1;
    }

    // Read from temporary file and detect keywords, identifiers, and constants
    printf("Keywords, Identifiers, and Constants:\n");
    while (fscanf(inputFile, "%s", word) != EOF) {
        if (isKeyword(word)) {
            printf("Keyword: %s\n", word);
        } else if (isIdentifier(word)) {
            printf("Identifier: %s\n", word);
        } else if (isConstant(word)) {
            printf("Constant: %s\n", word);
        }
    }

    fclose(inputFile);

    // Remove the temporary file
    remove("temp.txt");

    return 0;
}
