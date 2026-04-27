#include <iostream>
#include <string>

using namespace std;

int main() {
    string s; cin >> s;
    s.insert(0, 2 * s.size() % 3, '0');

    for (int i = 0; i < s.size();) {
        int c = 0, k = 4;
        while (k > 0) {
            c += (s[i++] - '0') * k;
            k /= 2;
        }
        cout << c;
    }
}