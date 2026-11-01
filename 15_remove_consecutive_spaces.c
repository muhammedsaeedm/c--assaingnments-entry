#include <stdio.h>
#include <string.h>

void clean_spaces(char *s) {
    if (s == NULL) return;

    int r = 0, w = 0;
    int sp = 0;

    while (s[r] != '\0') {
        if (s[r] == ' ') {
            if (!sp) {
                s[w++] = ' ';
                sp = 1;
            }
        } else {
            s[w++] = s[r];
            sp = 0;
        }
        r++;
    }
    s[w] = '\0';
}

int main(void) {
    char s[1024];

    printf("Enter a sentence with multiple consecutive spaces:\n");
    if (fgets(s, sizeof(s), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }

    clean_spaces(s);

    printf("Cleaned string: \"%s\"\n", s);

    return 0;
}
