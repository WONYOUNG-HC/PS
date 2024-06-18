#include <iostream>
#include <string>

using namespace std;

int n, k;
string str;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    cin >> str;

    string s;
    int idx = 0;
    for (int i = 0; i < k; i++) {
        while (idx < n && (s.empty() || s.back() >= str[idx])) {
            s.push_back(str[idx++]);
        }

        s.pop_back();
    }

    while (idx < n) {
        s.push_back(str[idx++]);
    }

    cout << s;
}