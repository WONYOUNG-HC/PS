#include <iostream>
#include <array>

using namespace std;

string s;
char a;
int q, l, r;
array<int, 26> sum[200010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;
    for (int i = 1; i <= s.size(); i++) {
        sum[i] = sum[i - 1];
        sum[i][s[i - 1] - 'a']++;
    }

    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> a >> l >> r;
        cout << sum[r + 1][a - 'a'] - sum[l][a - 'a'] << '\n';
    }
}