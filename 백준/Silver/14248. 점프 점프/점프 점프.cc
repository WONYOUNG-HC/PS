#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vector<int> stone(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> stone[i];

    int s; cin >> s;

    vector<bool> visited(n + 1);
    visited[s] = true;
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        int left = cur - stone[cur];
        int right = cur + stone[cur];

        if (left > 0) {
            visited[left] = true;
            q.push(left);
        }

        if (right <= n) {
            visited[right] = true;
            q.push(right);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (visited[i]) ans++;

    cout << ans;
}