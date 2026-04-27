#include <iostream>
#include <set>

using namespace std;

int main() {
    string str; cin >> str;
    set<string> s;

    for (int i = 0; i < str.length(); i++)
        s.insert(str.substr(i));

    for (auto& x : s) cout << x << '\n';
}