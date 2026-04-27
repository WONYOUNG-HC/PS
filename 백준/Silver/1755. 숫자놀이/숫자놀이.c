#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char s[110];
    int k;
} el;

int n, m;
int arr[110];
el ans[110];
char str[10][110] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int compare(const void* left, const void* right) {
    return strcmp(((el *)left)->s, ((el *)right)->s);
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = n; i <= m; i++) {
        char tmp[110];
        if (i < 10) {
            strcpy(tmp, str[i]);
        }
        else {
            strcpy(tmp, str[i / 10]);
            strcat(tmp, " ");
            strcat(tmp, str[i % 10]);
        }
        strcpy(ans[i - n].s, tmp);
        ans[i - n].k = i;
    }

    qsort(ans, m - n + 1, sizeof(el), compare);

    for (int i = 0; i < m - n + 1;) {
        for (int j = 0; j < 10 && i < m - n + 1; j++, i++) {
            printf("%d ", ans[i].k);
        }
        printf("\n");
    }
}