#include <stdio.h>
#include <string.h>

void to_lower(char *s) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] + ('a' - 'A');
        }
    }
}

int main(void) {
    char s[1024];

    printf("Enter a string: ");
    if (fgets(s, sizeof(s), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }

    to_lower(s);

    printf("Lowercase string: %s\n", s);

    return 0;
}
