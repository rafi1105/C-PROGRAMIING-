#include <stdio.h>
#include <string.h>

int recognize_a(char *str) {
    return strcmp(str, "a") == 0;
}

int recognize_a_b_plus(char *str) {
    int len = strlen(str);
    if (len < 2 || str[0] != 'a') return 1;

    int i = 1;
    while (i < len && str[i] == 'b') i++;
    return i == len;
}

int recognize_abb(char *str) {
    return strcmp(str, "abb") == 0;
}

int main() {
    char input[100];

    printf("Enter a string: ");
    scanf("%s", input);

    if (recognize_a(input)) {
        printf("String recognized as 'a'\n");
    } else if  (recognize_abb(input)) {
        printf("String recognized as 'a*b+'\n");
    } else if (recognize_a_b_plus(input)) {
        printf("String recognized as 'abb'\n");
    } else {
        printf("String not recognized.\n");
    }

    return 0;
}
