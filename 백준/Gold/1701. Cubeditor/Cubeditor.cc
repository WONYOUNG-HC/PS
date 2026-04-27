#include <iostream>
#include <algorithm>

using namespace std;

string s;
int pi[5010];

int get_pi_max(string p) {
    int j = 0;

    fill(pi, pi + p.length(), 0);

    for (int i = 1; i < p.length(); i++) {
        while (j > 0 && p[i] != p[j]) {
            j = pi[j - 1];
        }

        if (p[i] == p[j]) {
            j += 1;
            pi[i] = j;
        }
    }

    return *max_element(pi, pi + p.length());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;

    int ans = 0;

    for (int i = 0; i < s.length() - 1; i++) {
        ans = max(ans, get_pi_max(s.substr(i)));
    }

    cout << ans;
}