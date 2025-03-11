#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// Token types
typedef enum {
    TOKEN_NUMBER,
    TOKEN_IDENTIFIER,
    TOKEN_KEYWORD,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_STAR,
    TOKEN_SLASH,
    TOKEN_EQUAL,
    TOKEN_END,
    TOKEN_INVALID,
    TOKEN_COMMENT,
    TOKEN_MULTILINE_COMMENT
} TokenType;

typedef struct {
    TokenType type;
    int value;  // Used for numbers
    char identifier[64];  // Used for identifiers and keywords
    const char *start;  // Pointer to the start of the token in the input string
    int line;
    int letters;  // Number of letters in the comment
} Token;

// Keywords list
const char *keywords[] = {
    "int", "float", "if", "else", "while", "return", "void", NULL
};

// Lexer function prototypes
Token get_next_token(const char **input, int *line);
void print_token(Token token);
int is_keyword(const char *str);

// Check if a string is a keyword
int is_keyword(const char *str) {
    for (const char **kw = keywords; *kw != NULL; ++kw) {
        if (strcmp(str, *kw) == 0) {
            return 1;
        }
    }
    return 0;
}

// Get the next token from the input string
Token get_next_token(const char **input, int *line) {
    const char *p = *input;

    // Skip whitespace and track line numbers
    while (isspace(*p)) {
        if (*p == '\n') {
            (*line)++;
        }
        p++;
    }

    Token token;
    token.start = p;
    token.line = *line;
    token.letters = 0;
    if (isdigit(*p)) {
        token.type = TOKEN_NUMBER;
        token.value = strtol(p, (char **)&p, 10);
    } else if (isalpha(*p) || *p == '_') {
        // Identifiers and keywords
        const char *start = p;
        while (isalnum(*p) || *p == '_') {
            p++;
        }
        size_t length = p - start;
        strncpy(token.identifier, start, length);
        token.identifier[length] = '\0';

        if (is_keyword(token.identifier)) {
            token.type = TOKEN_KEYWORD;
        } else {
            token.type = TOKEN_IDENTIFIER;
        }
    } else {
        switch (*p) {
            case '+':
                token.type = TOKEN_PLUS;
                p++;
                break;
            case '-':
                token.type = TOKEN_MINUS;
                p++;
                break;
            case '*':
                token.type = TOKEN_STAR;
                p++;
                break;
            case '/':
                if (*(p + 1) == '/') {
                    // Single-line comment
                    token.type = TOKEN_COMMENT;
                    p += 2;
                    while (*p != '\n' && *p != '\0') {
                        if (isalpha(*p)) {
                            token.letters++;
                        }
                        p++;
                    }
                } else if (*(p + 1) == '*') {
                    // Multi-line comment
                    token.type = TOKEN_MULTILINE_COMMENT;
                    p += 2;
                    while (*p != '\0' && !(*p == '*' && *(p + 1) == '/')) {
                        if (*p == '\n') {
                            (*line)++;
                        }
                        if (isalpha(*p)) {
                            token.letters++;
                        }
                        p++;
                    }
                    if (*p == '*' && *(p + 1) == '/') {
                        p += 2;  // Skip the closing */
                    }
                } else {
                    token.type = TOKEN_SLASH;
                    p++;
                }
                break;
            case '=':
                token.type = TOKEN_EQUAL;
                p++;
                break;
            case '\0':
                token.type = TOKEN_END;
                break;
            default:
                token.type = TOKEN_INVALID;
                p++;
                break;
        }
    }

    *input = p;
    return token;
}

// Print the token type and value (if applicable)
void print_token(Token token) {
    switch (token.type) {
        case TOKEN_NUMBER:
            printf("NUMBER(%d)\n", token.value);
            break;
        case TOKEN_IDENTIFIER:
            printf("IDENTIFIER(%s)\n", token.identifier);
            break;
        case TOKEN_KEYWORD:
            printf("KEYWORD(%s)\n", token.identifier);
            break;
        case TOKEN_PLUS:
            printf("PLUS(+)\n");
            break;
        case TOKEN_MINUS:
            printf("MINUS(-)\n");
            break;
        case TOKEN_STAR:
            printf("STAR(*)\n");
            break;
        case TOKEN_SLASH:
            printf("SLASH(/)\n");
            break;
        case TOKEN_EQUAL:
            printf("EQUAL(=)\n");
            break;
        case TOKEN_END:
            printf("END\n");
            break;
        case TOKEN_INVALID:
            printf("INVALID(%c)\n", *token.start);
            break;
        case TOKEN_COMMENT:
            printf("COMMENT on line %d with %d letters\n", token.line, token.letters);
            break;
        case TOKEN_MULTILINE_COMMENT:
            printf("MULTILINE COMMENT starting on line %d with %d letters\n", token.line, token.letters);
            break;
    }
}

// AST node types
typedef enum {
    AST_NUMBER,
    AST_IDENTIFIER,
    AST_ASSIGNMENT,
    AST_ADD,
    AST_SUBTRACT,
    AST_MULTIPLY,
    AST_DIVIDE
} ASTNodeType;

typedef struct ASTNode {
    ASTNodeType type;
    int value; // Only used if type == AST_NUMBER
    char identifier[64]; // Used if type == AST_IDENTIFIER or AST_ASSIGNMENT
    struct ASTNode *left;
    struct ASTNode *right;
} ASTNode;

// Parser function prototypes
ASTNode* parse_expression(const char **input, int *line);
ASTNode* parse_term(const char **input, int *line);
ASTNode* parse_factor(const char **input, int *line);
ASTNode* parse_statement(const char **input, int *line);
ASTNode* parse_program(const char **input, int *line);
ASTNode* create_ast_node(ASTNodeType type, int value, const char *identifier, ASTNode *left, ASTNode *right);

// Create a new AST node
ASTNode* create_ast_node(ASTNodeType type, int value, const char *identifier, ASTNode *left, ASTNode *right) {
    ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
    node->type = type;
    node->value = value;
    if (identifier) {
        strncpy(node->identifier, identifier, sizeof(node->identifier));
    } else {
        node->identifier[0] = '\0';
    }
    node->left = left;
    node->right = right;
    return node;
}

// Parse a factor (number, identifier, or parenthesized expression)
ASTNode* parse_factor(const char **input, int *line) {
    Token token = get_next_token(input, line);
    print_token(token);
    if (token.type == TOKEN_NUMBER) {
        return create_ast_node(AST_NUMBER, token.value, NULL, NULL, NULL);
    } else if (token.type == TOKEN_IDENTIFIER) {
        return create_ast_node(AST_IDENTIFIER, 0, token.identifier, NULL, NULL);
    } else if (token.type == TOKEN_INVALID) {
        fprintf(stderr, "Error: Invalid token '%c'\n", *token.start);
        return NULL;
    } else if (token.type == TOKEN_COMMENT || token.type == TOKEN_MULTILINE_COMMENT) {
        // Skip comments
        return parse_factor(input, line);
    }
    return NULL; // Error: invalid factor
}

// Parse a term (factor * factor / factor)
ASTNode* parse_term(const char **input, int *line) {
    ASTNode *node = parse_factor(input, line);
    if (!node) return NULL;

    while (1) {
        Token token = get_next_token(input, line);
        if (token.type == TOKEN_STAR) {
            ASTNode *right = parse_factor(input, line);
            if (!right) return NULL;
            node = create_ast_node(AST_MULTIPLY, 0, NULL, node, right);
        } else if (token.type == TOKEN_SLASH) {
            ASTNode *right = parse_factor(input, line);
            if (!right) return NULL;
            node = create_ast_node(AST_DIVIDE, 0, NULL, node, right);
        } else if (token.type == TOKEN_COMMENT || token.type == TOKEN_MULTILINE_COMMENT) {
            // Skip comments
            continue;
        } else {
            (*input)--;
            break;
        }
    }
    return node;
}

// Parse an expression (term + term - term)
ASTNode* parse_expression(const char **input, int *line) {
    ASTNode *node = parse_term(input, line);
    if (!node) return NULL;

    while (1) {
        Token token = get_next_token(input, line);
        if (token.type == TOKEN_PLUS) {
            ASTNode *right = parse_term(input, line);
            if (!right) return NULL;
            node = create_ast_node(AST_ADD, 0, NULL, node, right);
        } else if (token.type == TOKEN_MINUS) {
            ASTNode *right = parse_term(input, line);
            if (!right) return NULL;
            node = create_ast_node(AST_SUBTRACT, 0, NULL, node, right);
        } else if (token.type == TOKEN_INVALID) {
            fprintf(stderr, "Error: Invalid token '%c'\n", *token.start);
            return NULL;
        } else if (token.type == TOKEN_COMMENT || token.type == TOKEN_MULTILINE_COMMENT) {
            // Skip comments
            continue;
        } else {
            (*input)--;
            break;
        }
    }
    return node;
}

ASTNode* parse_statement(const char **input, int *line) {
    Token token = get_next_token(input, line);
    print_token(token);

    if (token.type == TOKEN_KEYWORD) {
        if (strcmp(token.identifier, "int") == 0 || strcmp(token.identifier, "float") == 0) {
            Token identifier_token = get_next_token(input, line);
            if (identifier_token.type != TOKEN_IDENTIFIER) {
                fprintf(stderr, "Error: Expected identifier after keyword '%s'\n", token.identifier);
                return NULL;
            }
            print_token(identifier_token);

            Token equal_token = get_next_token(input, line);
            if (equal_token.type != TOKEN_EQUAL) {
                fprintf(stderr, "Error: Expected '=' after identifier '%s'\n", identifier_token.identifier);
                return NULL;
            }
            print_token(equal_token);

            ASTNode *expr = parse_expression(input, line);
            if (!expr) return NULL;

            return create_ast_node(AST_ASSIGNMENT, 0, identifier_token.identifier, expr, NULL);
        } else {
            fprintf(stderr, "Error: Unsupported keyword '%s'\n", token.identifier);
            return NULL;
        }
    } else if (token.type != TOKEN_END) {
        fprintf(stderr, "Error: Invalid statement\n");
        return NULL;
    }

    return NULL; // Error: invalid statement
}

// Parse the entire program (multiple statements)
ASTNode* parse_program(const char **input, int *line) {
    ASTNode *root = NULL;
    ASTNode *current = NULL;

    while (**input != '\0') {
        ASTNode *stmt = parse_statement(input, line);
        if (!stmt) {
            fprintf(stderr, "Error: Invalid statement\n");
            return NULL;
        }

        if (!root) {
            root = stmt;
        } else {
            current->right = stmt;
        }
        current = stmt;

        // Skip semicolons if they are used to separate statements
        Token token = get_next_token(input, line);
        if (token.type != TOKEN_END && token.type != TOKEN_INVALID) {
            (*input)--;
        }
    }

    return root;
}

// Code generation function prototypes
void generate_code(ASTNode *node);

// Generate code from the AST
void generate_code(ASTNode *node) {
    if (!node) return;

    switch (node->type) {
        case AST_NUMBER:
            printf("PUSH %d\n", node->value);
            break;
        case AST_IDENTIFIER:
            printf("LOAD %s\n", node->identifier);
            break;
        case AST_ASSIGNMENT:
            generate_code(node->left);
            printf("STORE %s\n", node->identifier);
            break;
        case AST_ADD:
            generate_code(node->left);
            generate_code(node->right);
            printf("ADD\n");
            break;
        case AST_SUBTRACT:
            generate_code(node->left);
            generate_code(node->right);
            printf("SUBTRACT\n");
            break;
        case AST_MULTIPLY:
            generate_code(node->left);
            generate_code(node->right);
            printf("MULTIPLY\n");
            break;
        case AST_DIVIDE:
            generate_code(node->left);
            generate_code(node->right);
            printf("DIVIDE\n");
            break;
    }
}

#define INITIAL_BUFFER_SIZE 256

// Function to dynamically read multiple lines of input
char* read_input_until_backtick() {
    size_t buffer_size = INITIAL_BUFFER_SIZE;
    size_t input_length = 0;
    char *input_buffer = (char *)malloc(buffer_size);
    if (!input_buffer) {
        fprintf(stderr, "Error allocating memory\n");
        exit(1);
    }

    printf("Enter your code (end input with ` on a new line):\n");

    while (1) {
        char line_buffer[256];
        if (!fgets(line_buffer, sizeof(line_buffer), stdin)) {
            fprintf(stderr, "Error reading input\n");
            free(input_buffer);
            exit(1);
        }

        // Check for backtick indicating end of input
        if (line_buffer[0] == '`' && (line_buffer[1] == '\n' || line_buffer[1] == '\0')) {
            break;
        }

        size_t line_length = strlen(line_buffer);
        if (input_length + line_length >= buffer_size) {
            buffer_size *= 2;
            input_buffer = (char *)realloc(input_buffer, buffer_size);
            if (!input_buffer) {
                fprintf(stderr, "Error reallocating memory\n");
                exit(1);
            }
        }

        strcpy(input_buffer + input_length, line_buffer);
        input_length += line_length;
    }

    return input_buffer;
}

int main() {
    char *input = read_input_until_backtick();

    int line = 1;
    const char *input_ptr = input;
    ASTNode *ast = parse_program(&input_ptr, &line);
   if (ast) {
        generate_code(ast);
        printf("END\n"); // Indicate end of program
    } else {
        fprintf(stderr, "Error: Invalid expression\n");
    }
    free(input);
    return 0;
}
