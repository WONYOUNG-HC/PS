#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int n;

void f(int start, int end, string &str) {
    if (start + 3 > end) {
        return;
    }

    int interval = (end - start) / 3;

    for (int i = start + interval; i < end - interval; i++) {
        str[i] = ' ';
    }

    f(start, start + interval, str);
    f(start + interval, end - interval, str);
    f(end - interval, end, str);
}

int main() {
    while (cin >> n) {
        string str(pow(3, n), '-');

        f(0, str.size(), str);

        cout << str << '\n';
    }
}