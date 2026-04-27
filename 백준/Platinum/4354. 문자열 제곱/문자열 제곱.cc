#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s;
int f[1000010];

void failure() {
    fill_n(f, s.length() + 10, 0);

    int j = 0;
    for (int i = 1; i < s.length(); i++) {
        while (j > 0 && s[i] != s[j])
            j = f[j - 1];

        if (s[i] == s[j])
            f[i] = ++j;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        cin >> s;
        if (s == ".")
            break;
        
        failure();
        int len = s.length() - f[s.length() - 1];
        
        cout << (s.length() % len ? 1 : s.length() / len) << '\n';
    }
}