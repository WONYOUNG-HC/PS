#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int ctoi(char c) {
    if (c < 60)
        return c - '0';
    return c - 'A' + 10;
}

int main() {
    string s; int n;
    cin >> s >> n;

    reverse(s.begin(), s.end());
    int ans = 0;

    for (int i = 0; i < s.length(); i++)
        ans += ctoi(s[i]) * pow(n, i);

    cout << ans;
}