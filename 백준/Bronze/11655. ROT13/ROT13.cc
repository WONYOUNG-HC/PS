#include <cstdio>

int main() {
    char c, t;
    while ((c = getchar()) != '\n') {
        if (97 <= c && c <= 122)
            t = ((c - 84) % 26) + 97;
        else if (65 <= c && c <= 90)
            t = ((c - 52) % 26) + 65;
        else
            t = c;
        printf("%c", t);
    }
}