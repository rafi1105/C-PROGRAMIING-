#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define EPSILON 'e'

void addFollow(char nonTerminal, char symbol);
void computeFollow(char nonTerminal);
void computeFirst(char nonTerminal);

int n = 0;  
char productions[MAX][MAX];
char followResult[26][MAX]; 
char firstResult[26][MAX];  
int isComputed[26];        

void addToSet(char set[][MAX], char nonTerminal, char symbol) {
    int i;
    for (i = 0; set[nonTerminal - 'S'][i] != '\0'; i++) {
        if (set[nonTerminal - 'S'][i] == symbol)
            return;
    }
    set[nonTerminal - 'S'][i] = symbol;
}

void computeFirst(char symbol) {
    if (symbol >= 'S' && symbol <= 'Z') {
        for (int i = 0; i < n; i++) {
            if (productions[i][0] == symbol) {
                if (productions[i][2] == EPSILON) {
                    addToSet(firstResult, symbol, EPSILON);
                } else {
                    int j = 2;
                    while (productions[i][j] != '\0') {
                        if (!(productions[i][j] >= 'S' && productions[i][j] <= 'Z')) {
                            addToSet(firstResult, symbol, productions[i][j]);
                            break;
                        } else {
                            computeFirst(productions[i][j]);
                            int k = 0;
                            while (firstResult[productions[i][j] - 'S'][k] != '\0') {
                                if (firstResult[productions[i][j] - 'S'][k] != EPSILON) {
                                    addToSet(firstResult, symbol, firstResult[productions[i][j] - 'S'][k]);
                                }
                                k++;
                            }
                            if (strchr(firstResult[productions[i][j] - 'S'], EPSILON) == NULL) {
                                break;
                            }
                            j++;
                        }
                    }
                }
            }
        }
    }
}

void computeFollow(char symbol) {
    if (isComputed[symbol - 'S'])
        return;

    isComputed[symbol - 'S'] = 1;

    if (symbol == productions[0][0]) {
        addToSet(followResult, symbol, '$');
    }

    for (int i = 0; i < n; i++) {
        for (int j = 2; j < strlen(productions[i]); j++) {
            if (productions[i][j] == symbol) {
                if (productions[i][j + 1] != '\0') {
                    int k = j + 1;
                    while (productions[i][k] != '\0') {
                        if (productions[i][k] >= 'S' && productions[i][k] <= 'Z') {
                            int l = 0;
                            while (firstResult[productions[i][k] - 'S'][l] != '\0') {
                                if (firstResult[productions[i][k] - 'S'][l] != EPSILON) {
                                    addToSet(followResult, symbol, firstResult[productions[i][k] - 'S'][l]);
                                }
                                l++;
                            }
                            if (strchr(firstResult[productions[i][k] - 'S'], EPSILON) == NULL) {
                                break;
                            }
                        } else {
                            addToSet(followResult, symbol, productions[i][k]);
                            break;
                        }
                        k++;
                    }
                    if (productions[i][k] == '\0' && symbol != productions[i][0]) {
                        computeFollow(productions[i][0]);
                        int m = 0;
                        while (followResult[productions[i][0] - 'S'][m] != '\0') {
                            addToSet(followResult, symbol, followResult[productions[i][0] - 'S'][m]);
                            m++;
                        }
                    }
                } else if (symbol != productions[i][0]) {
                    computeFollow(productions[i][0]);
                    int m = 0;
                    while (followResult[productions[i][0] - 'S'][m] != '\0') {
                        addToSet(followResult, symbol, followResult[productions[i][0] - 'S'][m]);
                        m++;
                    }
                }
            }
        }
    }
}

int main() {
    FILE *file;
    char buffer[MAX];

    file = fopen("grammar.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        buffer[strcspn(buffer, "\n")] = 0; 
        strcpy(productions[n++], buffer);
    }
    fclose(file);

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < MAX; j++) {
            followResult[i][j] = '\0';
            firstResult[i][j] = '\0';
        }
        isComputed[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        computeFirst(productions[i][0]);
    }

    for (int i = 0; i < n; i++) {
        computeFollow(productions[i][0]);
    }

    for (int i = 0; i < n; i++) {
        printf("FOLLOW(%c) = { ", productions[i][0]);
        for (int j = 0; j < MAX && followResult[productions[i][0] - 'S'][j] != '\0'; j++) {
            printf("%c ", followResult[productions[i][0] - 'S'][j]);
        }
        printf("}\n");
    }

    return 0;
}
if (input !=NULL){
    for (int i = 0; i = 0) {
    arry[][]=iuput;
    break;
}