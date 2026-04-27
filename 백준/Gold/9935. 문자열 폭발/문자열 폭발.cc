#include <iostream>
#include <vector>

using namespace std;

string a, b, s;

int main() {
    cin >> a >> b;

    for (char c : a) {
        s += c;
        if (s.size() >= b.size() && s.compare(s.size() - b.size(), s.size(), b) == 0)
            s.erase(s.size() - b.size(), s.size());
    }

    cout << (s.empty() ? "FRULA" : s);
}