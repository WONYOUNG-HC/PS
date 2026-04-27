#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n0 = 0, n1 = 0;
    char prev = '2';
    for (char c : s) {
        if (prev != c) {
            if (c == '0') n1++;
            else n0++;

            prev = c;
        }
    }

    if (prev ==  '0') n1++;
    else n0++;

    cout << (n0 > n1 ? n1 : n0);
}