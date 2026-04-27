#include <iostream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<string, int> m;
    string s; int n = 0;
    while (getline(cin, s)) {
        m.find(s) == m.end() ? m[s] = 1 : m[s] += 1;
        n++;
    }

    cout << fixed; cout.precision(4);
    for (const auto& pr : m)
        cout << pr.first << " " << (double)pr.second / n * 100 << '\n';
}