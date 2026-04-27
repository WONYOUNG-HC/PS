#include <iostream>
#include <vector>

using namespace std;

string s, p;
int f[1000010];
vector<int> ans;

void failure() {
    int j = 0;
    for (int i = 1; i < p.length(); i++) {
        while (j > 0 && p[i] != p[j])
            j = f[j - 1];

        if (p[i] == p[j])
            f[i] = ++j;
    }
}

void kmp() {
    int j = 0;
    for (int i = 0; i < s.length(); i++) {
        while (j > 0 && s[i] != p[j])
            j = f[j - 1];

        if (s[i] == p[j]) {
            if (j == p.length() - 1) {
                ans.push_back(i - p.length() + 2);
                j = f[j];
            }
            else {
                j++;
            }
        }
    }
}

int main() {
    getline(cin, s);
    getline(cin, p);

    failure();
    kmp();

    cout << ans.size() << '\n';
    for (int x : ans)
        cout << x << ' ';
}