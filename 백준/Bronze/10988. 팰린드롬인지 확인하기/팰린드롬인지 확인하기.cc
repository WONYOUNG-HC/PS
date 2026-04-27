#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string s; cin >> s;
    cout << equal(s.rbegin(), s.rbegin() + s.size() / 2, s.substr(0, s.size() / 2).begin());
}