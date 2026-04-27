#include <stdio.h>

int main() {
    int tc; scanf("%d", &tc);
    while (tc--) {
        int balance;
        scanf("%d", &balance);

        printf("%d ", balance / 25);
        balance %= 25;

        printf("%d ", balance / 10);
        balance %= 10;

        printf("%d ", balance / 5);
        balance %= 5;

        printf("%d\n", balance);
    }
}