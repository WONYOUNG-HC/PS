#include <iostream>
#include <string>

using namespace std;

int main() {
    double a = 0, b = 0;

    for (int i = 0; i < 20; i++) {
        string _, s; double n;
        cin >> _ >> n >> s;

        if (s[0] != 'P')
            a += (s[0] != 'F' ? ('E' - s[0]) + (s[1] == '+' ? 0.5 : 0) : 0) * n, b += n;
    }

    cout << fixed;
    cout << a / b;
}