#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;

    cin >> tc;

    while (tc--) {
        int m;

        cin >> m;

        vector<int> ans;
        priority_queue<int, vector<int>, greater<int>> gpq;
        priority_queue<int> lpq;

        for (int i = 0; i < m; i++) {
            int a;

            cin >> a;

            if (lpq.empty() || a < lpq.top()) {
                lpq.push(a);
            } else {
                gpq.push(a);
            }

            if (lpq.size() > gpq.size() + 1) {
                gpq.push(lpq.top());
                lpq.pop();
            } else if (gpq.size() > lpq.size() + 1) {
                lpq.push(gpq.top());
                gpq.pop();
            }

            if (i % 2 > 0) {
                continue;
            }

            if (lpq.size() > gpq.size()) {
                ans.push_back(lpq.top());
            } else {
                ans.push_back(gpq.top());
            }
        }

        cout << ans.size() << '\n';

        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << ' ';

            if (i > 0 && i % 10 == 9) {
                cout << '\n';
            }
        }

        cout << '\n';
    }
}