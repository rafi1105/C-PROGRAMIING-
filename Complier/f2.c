#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_valid_email(const char *email) {
    int state = 0;
    const char *p = email;

    while (*p) {
        switch (state) {
            case 0: // local part before @
                if (isalnum(*p) || *p == '.' || *p == '_') {
                    state = 0;
                } else if (*p == '@') {
                    state = 1;
                } else {
                    return 0;
                }
                break;
            case 1: 
                if (isalnum(*p) || *p == '-') {
                    state = 1;
                } else if (*p == '.') {
                    state = 2;
                } else {
                    return 0;
                }
                break;
            case 2:
                if (isalpha(*p)) {
                    state = 3;
                } else {
                    return 0;
                }
                break;
            case 3: 
                if (isalpha(*p)) {
                    state = 3;
                } else {
                    return 0;
                }
                break;
            default:
                return 0;
        }
        p++;
    }

    return state == 3;
}

int main() {
    char email[100];

    printf("Enter an email address: ");
    scanf("%s", email);

    if (is_valid_email(email)) {
        printf("Valid email address.\n");
    } else {
        printf("Invalid email address.\n");
    }

    return 0;
}
