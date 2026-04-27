#include <cstdio>

int main() {
    char c;
    while ((c = getchar()) != '\n')
        if (65 <= c && c <= 90) printf("%c", c);
}