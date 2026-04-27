#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    multiset<string> ms;
    string str;
    for (int i=0; i<n; i++) {
        cin >> str;
        ms.insert(str);
    }

    int ans = 0;
    multiset<string>::iterator iter;
    for (int i=0; i<m; i++) {
        cin >> str;
        iter = ms.find(str);

        if (iter != ms.end())
            ans++;
    }

    cout << ans;
}