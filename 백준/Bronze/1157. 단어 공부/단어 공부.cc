#include <iostream>

using namespace std;

int a[91];

int main() {
    string s; cin >> s;

    for (char c : s)
        c >= 'a' ? a[c - 'a' + 'A'] += 1 : a[c] += 1;

    int k = 65; bool flag = true;
    for (int i = 66; i < 91; i++) {
        if (a[i] > a[k]) k = i, flag = true;
        else if (a[i] == a[k]) flag = false;
    }

    cout << (flag ? (char)k : '?');
}