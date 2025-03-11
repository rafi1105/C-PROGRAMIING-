#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STATES 10
#define MAX_ALPHABET 2

typedef struct {
    int numStates;
    int numAlphabets;
    int transitions[MAX_STATES][MAX_ALPHABET][MAX_STATES];
    int finalStates[MAX_STATES];
} NFA;

typedef struct {
    int numStates;
    int numAlphabets;
    int transitions[MAX_STATES][MAX_ALPHABET];
    int finalStates[MAX_STATES];
} DFA;

void initializeNFA(NFA *nfa, int numStates, int numAlphabets) {
    nfa->numStates = numStates;
    nfa->numAlphabets = numAlphabets;
    memset(nfa->transitions, 0, sizeof(nfa->transitions));
    memset(nfa->finalStates, 0, sizeof(nfa->finalStates));
}

void addTransitionNFA(NFA *nfa, int fromState, int symbol, int toState) {
    nfa->transitions[fromState][symbol][toState] = 1;
}

void setFinalStateNFA(NFA *nfa, int state) {
    nfa->finalStates[state] = 1;
}

int isFinalStateNFA(NFA *nfa, int state) {
    return nfa->finalStates[state];
}

void initializeDFA(DFA *dfa, int numStates, int numAlphabets) {
    dfa->numStates = numStates;
    dfa->numAlphabets = numAlphabets;
    memset(dfa->transitions, -1, sizeof(dfa->transitions));
    memset(dfa->finalStates, 0, sizeof(dfa->finalStates));
}

void addTransitionDFA(DFA *dfa, int fromState, int symbol, int toState) {
    dfa->transitions[fromState][symbol] = toState;
}

void setFinalStateDFA(DFA *dfa, int state) {
    dfa->finalStates[state] = 1;
}

int isFinalStateDFA(DFA *dfa, int state) {
    return dfa->finalStates[state];
}

int stateExists(int state, int *states, int numStates) {
    for (int i = 0; i < numStates; i++) {
        if (states[i] == state) {
            return 1;
        }
    }
    return 0;
}

void convertNFAToDFA(NFA *nfa, DFA *dfa) {
    int stateMapping[MAX_STATES][MAX_STATES];
    int newStateCount = 1;
    int stateQueue[MAX_STATES * MAX_STATES];
    int front = 0, rear = 0;
    memset(stateMapping, -1, sizeof(stateMapping));
    
    stateMapping[0][0] = 0;
    stateQueue[rear++] = 0;

    while (front < rear) {
        int currentState = stateQueue[front++];
        for (int symbol = 0; symbol < nfa->numAlphabets; symbol++) {
            int newStates[MAX_STATES];
            int newStateCount = 0;
            for (int i = 0; i < nfa->numStates; i++) {
                if (stateMapping[currentState][i] != -1) {
                    for (int j = 0; j < nfa->numStates; j++) {
                        if (nfa->transitions[i][symbol][j] && !stateExists(j, newStates, newStateCount)) {
                            newStates[newStateCount++] = j;
                        }
                    }
                }
            }

            int newState = -1;
            for (int i = 0; i < newStateCount; i++) {
                if (stateMapping[currentState][newStates[i]] == -1) {
                    stateMapping[currentState][newStates[i]] = newStateCount;
                    stateQueue[rear++] = newStateCount;
                }
                newState = stateMapping[currentState][newStates[i]];
            }

            if (newState != -1) {
                addTransitionDFA(dfa, currentState, symbol, newState);
            }
        }
    }

    for (int i = 0; i < dfa->numStates; i++) {
        for (int j = 0; j < nfa->numStates; j++) {
            if (stateMapping[i][j] != -1 && isFinalStateNFA(nfa, j)) {
                setFinalStateDFA(dfa, i);
            }
        }
    }
}

int main() {
    NFA nfa;
    initializeNFA(&nfa, 3, 2);

    // Define NFA transitions
    addTransitionNFA(&nfa, 0, 0, 0);
    addTransitionNFA(&nfa, 0, 0, 2);
    addTransitionNFA(&nfa, 0, 1, 1);
    addTransitionNFA(&nfa, 1, 0, 1);
    addTransitionNFA(&nfa, 1, 1, 1);
    addTransitionNFA(&nfa, 1, 1, 2);
    addTransitionNFA(&nfa, 2, 0, 2);
    addTransitionNFA(&nfa, 2, 1, 2);

    // Define final states of NFA
    setFinalStateNFA(&nfa, 2);

    DFA dfa;
    initializeDFA(&dfa, MAX_STATES, 2);

    convertNFAToDFA(&nfa, &dfa);

    // Print DFA transitions
    printf("DFA Transitions:\n");
    for (int i = 0; i < dfa.numStates; i++) {
        for (int j = 0; j < dfa.numAlphabets; j++) {
            if (dfa.transitions[i][j] != -1) {
                printf("From state %d on symbol %d to state %d\n", i, j, dfa.transitions[i][j]);
            }
        }
    }

    // Print DFA final states
    printf("DFA Final States:\n");
    for (int i = 0; i < dfa.numStates; i++) {
        if (dfa.finalStates[i]) {
            printf("State %d\n", i);
        }
    }

    return 0;
}
