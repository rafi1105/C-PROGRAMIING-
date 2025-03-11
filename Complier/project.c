#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKEN_LENGTH 100
#define NUM_KEYWORDS 6
#define MAX_SYMBOLS 100
#define MAX_STATES 100
#define MAX_ALPHABET 100
// Keywords of the language
const char *keywords[NUM_KEYWORDS] = {"int", "if", "then", "else", "endif", "print"};

// Structure to hold information about symbols
typedef struct {
    char name[MAX_TOKEN_LENGTH];
    char type[MAX_TOKEN_LENGTH];
} Symbol;

// Symbol table
Symbol symbolTable[MAX_SYMBOLS];
int symbolCount = 0;

// Function to check if a string is a keyword
int isKeyword(const char *str) {
    for (int i = 0; i < NUM_KEYWORDS; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a character is a special symbol
int isSpecialSymbol(char ch) {
    return (ch == ',' || ch == ';' || ch == '(' || ch == ')' || ch == '[' || ch == ']');
}
int Equation(char ch) {
    return (ch == '=' );
}
// Function to check if a character is an operator
int isOperator(char ch) {
    return (ch == '-' || ch == '+' || ch == '*' || ch == '/' || ch == '>' || ch == '<' || ch == '=' || ch == '&' || ch == '|' || ch == '!' || ch == '%' || ch == '^' || ch == '~' || ch == '?' || ch == ':' || ch == '++' || ch == '--');
}

// Function to add a symbol to the symbol table
void addSymbol(const char *name, const char *type) {
    for (int i = 0; i < symbolCount; i++) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            return; // Symbol already exists, no need to add
        }
    }
    strcpy(symbolTable[symbolCount].name, name);
    strcpy(symbolTable[symbolCount].type, type);
    symbolCount++;
}

// Function to print the symbol table
void printSymbolTable() {
    printf("Symbol Table:\n");
    printf("Name\tType\n");
    for (int i = 0; i < symbolCount; i++) {
        printf("%s\t%s\n", symbolTable[i].name, symbolTable[i].type);
    }
}

// Function to tokenize the input
void tokenize(const char *input) {
    int i = 0;
    char comment[1000] = "";
    int comment_mode = 0; // 1 when inside comment, 0 otherwise

    while (input[i] != '\0' && input[i] != '.') {
        // Skip white spaces
        if (isspace(input[i])) {
            i++;
            continue;
        }

        // Check for comment mode
        if (input[i] == '`') {
            if (comment_mode == 0) {
                comment_mode = 1;
            } else {
                comment_mode = 0;
                if (strlen(comment) > 0) {
                    printf("It is a comment: %s\n", comment);
                    memset(comment, 0, sizeof(comment));
                } else {
                    printf("It is not a comment\n");
                }
            }
            i++;
            continue;
        }

        // Inside comment mode
        if (comment_mode) {
            strncat(comment, &input[i], 1);
            i++;
            continue;
        }

        // Identifier or keyword
        if (isalpha(input[i])) {
            char buffer[MAX_TOKEN_LENGTH];
            int j = 0;
            while (isalnum(input[i])) {
                buffer[j++] = input[i++];
            }
            buffer[j] = '\0';
            if (isKeyword(buffer)) {
                printf("Keyword: %s\n", buffer);
            } else {
                printf("Identifier: %s\n", buffer);
                addSymbol(buffer, "variable"); // Add identifier to symbol table
            }
        }
        // Number (integer)
        else if (isdigit(input[i]) || (input[i] == '-' && isdigit(input[i+1]))) {
            char buffer[MAX_TOKEN_LENGTH];
            int j = 0;
            if (input[i] == '-') {
                buffer[j++] = input[i++];
            }
            while (isdigit(input[i])) {
                buffer[j++] = input[i++];
            }
            buffer[j] = '\0';
            printf("Constant: %s\n", buffer);
        }
        // Special symbol
        else if (isSpecialSymbol(input[i])) {
            printf("Special Symbol: %c\n", input[i]);
            i++;
        }
          else if (Equation(input[i])) {
            printf("Equation: %c\n", input[i]);
            i++;
        }
        // Operator
        else if (input[i] == '+' && input[i + 1] == '+') {
            printf("Operator: Increment\n");
            i += 2; // Move to the next token
        }
          else if (input[i] == '-' && input[i + 1] == '-') {
            printf("Operator: Decrement\n");
            i += 2; // Move to the next token
        }
        // Unknown character
        else {
            printf("Unknown: %c\n", input[i]);
            i++;
        }
    }

    if (comment_mode && strlen(comment) > 0) {
        printf("It is a comment: %s\n", comment);
    }
}
// DFA to nfa
typedef struct {
    int fromState;
    char inputSymbol;
    int toState;
} DFATransition;

// Structure to represent a DFA
typedef struct {
    int numStates;
    int numSymbols;
    int initialState;
    int numAcceptStates;
    int acceptStates[MAX_STATES];
    DFATransition transitions[MAX_STATES][MAX_ALPHABET];
} DFA;

// Structure to represent an NFA transition
typedef struct {
    int fromState;
    char inputSymbol;
    int toState;
} NFATransition;

// Structure to represent an NFA
typedef struct {
    int numStates;
    int numSymbols;
    int initialState;
    int numAcceptStates;
    int acceptStates[MAX_STATES];
    NFATransition transitions[MAX_STATES][MAX_ALPHABET];
} NFA;

// Function to convert DFA to NFA
NFA convertDFAtoNFA(const DFA *dfa) {
    NFA nfa;
    nfa.numStates = dfa->numStates;
    nfa.numSymbols = dfa->numSymbols;
    nfa.initialState = dfa->initialState;
    nfa.numAcceptStates = dfa->numAcceptStates;
    memcpy(nfa.acceptStates, dfa->acceptStates, sizeof(dfa->acceptStates));
    memcpy(nfa.transitions, dfa->transitions, sizeof(dfa->transitions));
    return nfa;
}

// Function to display NFA
void displayNFA(const NFA *nfa) {
    printf("NFA Details:\n");
    printf("Number of States: %d\n", nfa->numStates);
    printf("Number of Symbols: %d\n", nfa->numSymbols);
    printf("Initial State: %d\n", nfa->initialState);
    printf("Number of Accept States: %d\n", nfa->numAcceptStates);
    printf("Accept States: ");
    for (int i = 0; i < nfa->numAcceptStates; i++) {
        printf("%d ", nfa->acceptStates[i]);
    }
    printf("\n");

    printf("Transitions:\n");
    for (int i = 0; i < nfa->numStates; i++) {
        for (int j = 0; j < nfa->numSymbols; j++) {
            NFATransition transition = nfa->transitions[i][j];
            if (transition.toState != -1) {
                printf("From State %d on symbol %c to State %d\n", transition.fromState, transition.inputSymbol, transition.toState);
            }
        }
    }
}

// Function to get user input for DFA
DFA getDFAFromUser() {
    DFA dfa;
    printf("Enter the number of states: ");
    scanf("%d", &dfa.numStates);
    printf("Enter the number of input symbols: ");
    scanf("%d", &dfa.numSymbols);
    printf("Enter the initial state: ");
    scanf("%d", &dfa.initialState);
    printf("Enter the number of accept states: ");
    scanf("%d", &dfa.numAcceptStates);
    printf("Enter the accept states: ");
    for (int i = 0; i < dfa.numAcceptStates; i++) {
        scanf("%d", &dfa.acceptStates[i]);
    }
    printf("Enter transitions in the format (fromState inputSymbol toState):\n");
    for (int i = 0; i < dfa.numStates; i++) {
        for (int j = 0; j < dfa.numSymbols; j++) {
            int fromState, toState;
            char inputSymbol;
            printf("Transition from state %d on symbol: ", i);
            scanf(" %c", &inputSymbol); // Space before %c to consume newline character
            printf(" to state: ");
            scanf("%d", &toState);
            dfa.transitions[i][j].fromState = i;
            dfa.transitions[i][j].inputSymbol = inputSymbol;
            dfa.transitions[i][j].toState = toState;
        }
    }
    return dfa;
}

int main() {
 int choice;
    char input[1000];

    printf("Select the type of input processing:\n");
    printf("1. Syntax Table\n");
    printf("2. DFA to NFA Conversion\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar(); // Consume newline character

    switch (choice) {
        case 1:
            printf("Enter the code and comment (use ` to start and end the comment). Enter '.' to end:\n");
            while (input[0] != '.') {
                fgets(input, sizeof(input), stdin);
                tokenize(input);
            }
            printSymbolTable();
            break;
        case 2:
             DFA dfa = getDFAFromUser();
    NFA nfa = convertDFAtoNFA(&dfa);
    displayNFA(&nfa); ;
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}