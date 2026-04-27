#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char s[21]; int tc;
    scanf("%d", &tc);
    while (tc) {
        scanf("%s", s);
        for (int i = strlen(s) - 1; i >= 0; i--)
            printf("%c", s[i]);
        printf(" ");

        if (getchar() == '\n') {
            printf("\n");
            tc--;
        }
    }
}