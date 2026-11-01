#include <stdio.h>
#include <string.h>

int is_pangram(const char *s) {
    int seen[26] = {0};
    int cnt = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        char ch = s[i];
        int idx = -1;

        if (ch >= 'a' && ch <= 'z') {
            idx = ch - 'a';
        } else if (ch >= 'A' && ch <= 'Z') {
            idx = ch - 'A';
        }

        if (idx != -1 && !seen[idx]) {
            seen[idx] = 1;
            cnt++;
            if (cnt == 26) {
                return 1;
            }
        }
    }

    return (cnt == 26);
}

int main(void) {
    char s[1024];

    printf("Enter a sentence to check for pangram:\n");
    if (fgets(s, sizeof(s), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }

    if (is_pangram(s)) {
        printf("Result: The entered text IS A PANGRAM (contains all 26 English letters).\n");
    } else {
        printf("Result: The entered text is NOT a pangram.\n");
    }

    return 0;
}
