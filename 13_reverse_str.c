#include <stdio.h>
#include <string.h>

void reverse_str(char *s) {
    int l = 0;
    int r = (int)strlen(s) - 1;

    while (l < r) {
        char temp = s[l];
        s[l] = s[r];
        s[r] = temp;
        l++;
        r--;
    }
}

int main(void) {
    char s[256];

    printf("Enter a string to reverse: ");
    if (fgets(s, sizeof(s), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }

    reverse_str(s);

    printf("Reversed string: \"%s\"\n", s);

    return 0;
}
