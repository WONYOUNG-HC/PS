#include <iostream>

using namespace std;
using pii = pair<int, int>;

int n, m, l, k;
pii arr[110];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> l >> k;

    for (int i = 0; i < k; i++) {
        cin  >> arr[i].first >> arr[i].second;
    }

    int ans = 110;

    for (int i = 0; i < k; i++) {
        auto [x1, y1] = arr[i];

        for (int j = 0; j < k; j++) {
            auto [x2, y2] = arr[j];
            int cnt = 0;

            for (int p = 0; p < k; p++) {
                auto [x3, y3] = arr[p];

                if (x1 <= x3 && x3 <= x1 + l && y2 <= y3 && y3 <= y2 + l) {
                    cnt += 1;
                }
            }

            ans = min(ans, k - cnt);
        }
    }

    cout << ans;
}