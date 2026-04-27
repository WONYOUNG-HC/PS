#include <iostream>
#include <string>

using namespace std;

int main() {
    string s; cin >> s;

    bool v = false;
    string coef;
    for (char c : s) {
        if (c == 'x') {
            if (coef != "2" && coef != "-2")
                cout << stoi(coef) / 2;
            else if (coef == "-2")
                cout << '-';

            cout << "xx";

            coef.clear();
            v = true;
        }
        else if (c != '+') {
            coef += c;
        }
    }

    if (coef == "0" || coef == "-0")
        coef.clear();

    if (v && coef.front() != '-') {
        cout << '+';
    }

    if (!coef.empty()) {
        if (coef == "-1")
            cout << '-';
        else if (coef != "1")
            cout << stoi(coef);

        cout << "x+";
    }

    cout << "W";
}