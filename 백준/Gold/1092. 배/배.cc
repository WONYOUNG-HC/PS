#include <iostream>
#include <set>

using namespace std;

int n, m;
int crane[50];
multiset<int> weight;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int c;

        cin >> c;

        crane[i] = c;
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        int w;

        cin >> w;

        weight.insert(w);
    }

    int ans = 0;

    while (true) {
        int cnt = weight.size();

        for (int i = 0; i < n; i++) {
            int c = crane[i];
            
            if (weight.empty()) {
                break;
            }

            auto it = weight.lower_bound(c);

            if ((it == weight.end() || *it > c) && it != weight.begin()) {
                it--;
            }

            if (*it <= c) {
                weight.erase(it);
            }
        }

        ans += 1;

        if (weight.size() == 0 || weight.size() == cnt) {
            break;
        }
    }

    if (!weight.empty()) {
        ans = -1;
    }

    cout << ans;
}