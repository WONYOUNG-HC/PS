#include <iostream>

using namespace std;

int main() {
    char a, b; int ans = 0;
    while ((b = getchar()) != '\n') {
        ans += ((a == '(' && b == '(') || (a == ')' && b == ')') ? 5 : 10);
        a = b;
    }

    cout << ans;
}