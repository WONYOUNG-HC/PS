#include <iostream>
#include <string>

using namespace std;

void f(string& s, char c1, char c2) {
    for (int i = 0; i < s.length(); i++)
        s[i] == c1 && (s[i] = c2);
}

int main() {
    string a, b;
    cin >> a >> b;

    f(a, '6', '5');
    f(b, '6', '5');
    cout << stoi(a) + stoi(b) << ' ';

    f(a, '5', '6');
    f(b, '5', '6');
    cout << stoi(a) + stoi(b);
}