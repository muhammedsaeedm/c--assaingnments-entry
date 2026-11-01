#include <stdio.h>
#include <string.h>

int is_palindrome(const char *s) {
    int l = 0;
    int r = (int)strlen(s) - 1;

    while (l < r) {
        if (s[l] != s[r]) {
            return 0;
        }
        l++;
        r--;
    }
    return 1;
}

int main(void) {
    char s[256];

    printf("Enter a string: ");
    if (fgets(s, sizeof(s), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }

    if (is_palindrome(s)) {
        printf("\"%s\" is a PALINDROME.\n", s);
    } else {
        printf("\"%s\" is NOT a palindrome.\n", s);
    }

    return 0;
}
