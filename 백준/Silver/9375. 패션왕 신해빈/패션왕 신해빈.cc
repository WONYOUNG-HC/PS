#include <iostream>
#include <map>

using namespace std;

int main() {

    int tc, n;
    cin >> tc;

    string name, type;
    while (tc--) {
        cin >> n;

        map<string, int> m;
        pair<map<string, int>::iterator, bool> pr;
        for (int i=0; i<n; i++) {
            cin >> name >> type;

            pr = m.insert(pair<string, int>(type, 1));
            if (!pr.second)
                m[type] += 1;

        }

        int ans = 1;
        for (auto & j : m)
            ans *= j.second + 1;

        cout << ans - 1 << '\n';
    }
}