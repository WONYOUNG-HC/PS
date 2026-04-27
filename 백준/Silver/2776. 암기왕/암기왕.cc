#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        multiset<int> note1;
        for (int i = 0; i < n; i++) {
            int c;
            cin >> c;
            note1.insert(c);
        }

        int m;
        cin >> m;

        vector<int> note2(m);
        for (int i = 0; i < m; i++)
            cin >> note2[i];

        for (int i: note2) {
            if (note1.find(i) == note1.end())
                cout << 0 << '\n';
            else
                cout << 1 << '\n';
        }
    }
}