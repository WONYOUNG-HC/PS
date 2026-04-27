#include <iostream>

using namespace std;

string s;
long long k;
int pi[500010];

void make_pi() {
    int j = 0;

    for (int i = 1; i < s.size(); i++) {
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }

        if (s[i] == s[j]) {
            j += 1;
            pi[i] = j;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s >> k;

    make_pi();

    cout << (k - 1) * (s.size() - pi[s.size() - 1]) + s.size();
}