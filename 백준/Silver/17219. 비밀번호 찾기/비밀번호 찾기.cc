#include <iostream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    string site, password;
    map<string, string> mp;
    for (int i=0; i<n; i++) {
        cin >> site >> password;
        mp[site] = password;
    }

    for (int i=0; i<m; i++) {
        cin >> site;
        cout << mp[site] << '\n';
    }
}