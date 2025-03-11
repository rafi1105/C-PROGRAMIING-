#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STATES 100
#define MAX_SYMBOLS 26

typedef struct {
    int transitions[MAX_STATES][MAX_SYMBOLS];
    bool epsilon_transitions[MAX_STATES][MAX_STATES];
    int num_states;
    int num_symbols;
    int start_state;
    bool accepting_states[MAX_STATES];
} EpsilonNFA;

typedef struct {
    int transitions[MAX_STATES][MAX_SYMBOLS];
    int num_states;
    int num_symbols;
    int start_state;
    bool accepting_states[MAX_STATES];
} DFA;

void epsilon_closure(EpsilonNFA *nfa, bool closure[MAX_STATES], int state) {
    bool stack[MAX_STATES];
    memset(stack, false, sizeof(stack));
    stack[state] = true;

    while (true) {
        bool progress = false;
        for (int i = 0; i < nfa->num_states; i++) {
            if (stack[i]) {
                stack[i] = false;
                if (!closure[i]) {
                    closure[i] = true;
                    progress = true;
                    for (int j = 0; j < nfa->num_states; j++) {
                        if (nfa->epsilon_transitions[i][j]) {
                            stack[j] = true;
                        }
                    }
                }
            }
        }
        if (!progress) break;
    }
}

void convert_to_dfa(EpsilonNFA *nfa, DFA *dfa) {
    bool state_sets[MAX_STATES][MAX_STATES];
    int set_count = 0;

    memset(state_sets, false, sizeof(state_sets));
    memset(dfa->transitions, -1, sizeof(dfa->transitions));
    dfa->num_states = 0;
    dfa->num_symbols = nfa->num_symbols;

    // Initial state closure
    epsilon_closure(nfa, state_sets[set_count], nfa->start_state);
    dfa->start_state = set_count++;
    dfa->num_states++;

    for (int i = 0; i < set_count; i++) {
        for (int sym = 0; sym < nfa->num_symbols; sym++) {
            bool new_state_set[MAX_STATES];
            memset(new_state_set, false, sizeof(new_state_set));

            for (int s = 0; s < nfa->num_states; s++) {
                if (state_sets[i][s]) {
                    int next_state = nfa->transitions[s][sym];
                    if (next_state != -1) {
                        epsilon_closure(nfa, new_state_set, next_state);
                    }
                }
            }

            bool found = false;
            for (int j = 0; j < set_count; j++) {
                if (memcmp(state_sets[j], new_state_set, sizeof(new_state_set)) == 0) {
                    dfa->transitions[i][sym] = j;
                    found = true;
                    break;
                }
            }

            if (!found) {
                memcpy(state_sets[set_count], new_state_set, sizeof(new_state_set));
                dfa->transitions[i][sym] = set_count;
                dfa->num_states++;
                set_count++;
            }
        }

        for (int s = 0; s < nfa->num_states; s++) {
            if (state_sets[i][s] && nfa->accepting_states[s]) {
                dfa->accepting_states[i] = true;
                break;
            }
        }
    }
}

void initialize_nfa(EpsilonNFA *nfa, int num_states, int num_symbols, int start_state) {
    nfa->num_states = num_states;
    nfa->num_symbols = num_symbols;
    nfa->start_state = start_state;
    memset(nfa->transitions, -1, sizeof(nfa->transitions));
    memset(nfa->epsilon_transitions, false, sizeof(nfa->epsilon_transitions));
    memset(nfa->accepting_states, false, sizeof(nfa->accepting_states));
}

void initialize_dfa(DFA *dfa) {
    memset(dfa->transitions, -1, sizeof(dfa->transitions));
    memset(dfa->accepting_states, false, sizeof(dfa->accepting_states));
}

void print_dfa(DFA *dfa) {
    printf("Number of DFA states: %d\n", dfa->num_states);
    printf("DFA start state: %d\n", dfa->start_state);
    printf("DFA accepting states: ");
    for (int i = 0; i < dfa->num_states; i++) {
        if (dfa->accepting_states[i]) {
            printf("%d ", i);
        }
    }
    printf("\nDFA transitions:\n");
    for (int i = 0; i < dfa->num_states; i++) {
        for (int sym = 0; sym < dfa->num_symbols; sym++) {
            if (dfa->transitions[i][sym] != -1) {
                printf("State %d --%c--> State %d\n", i, 'a' + sym, dfa->transitions[i][sym]);
            }
        }
    }
}

int main() {
    EpsilonNFA nfa;
    DFA dfa;

    // Example NFA initialization
    initialize_nfa(&nfa, 3, 2, 0);
    nfa.transitions[0][0] = 1; // State 0 --a--> State 1
    nfa.epsilon_transitions[1][2] = true; // State 1 --ε--> State 2
    nfa.accepting_states[2] = true;

    initialize_dfa(&dfa);
    convert_to_dfa(&nfa, &dfa);
    print_dfa(&dfa);

    return 0;
}
