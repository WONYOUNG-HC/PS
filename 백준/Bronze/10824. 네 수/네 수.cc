#include <iostream>

using namespace std;

int len(long long x) {
    int i = 1;

    while (x / i > 0)
        i *= 10;

    return i;
}

int main() {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;

    a = a * len(b) + b;
    c = c * len(d) + d;

    cout << a + c;
}