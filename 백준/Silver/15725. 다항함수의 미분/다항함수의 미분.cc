#include <iostream>
#include <string>

using namespace std;

int main() {
    string s; cin >> s;

    string coef;
    for (char c : s) {
        if (c == 'x') {
            if (coef.empty() || coef == "-")
                coef += '1';

            cout << stoi(coef);

            return 0;
        }

        coef += c;
    }

    cout << 0;
}