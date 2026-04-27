#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;

    vector<bool> visited(f + 1);
    queue<pair<int, int>> q;
    q.emplace(s, 0);

    while (!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (cur == g) {
            cout << cnt;
            return 0;
        }

        int up = cur + u, down = cur - d;

        if (up <= f && !visited[up]) {
            visited[up] = true;
            q.emplace(up, cnt + 1);
        }
        if (down >= 1 && !visited[down]) {
            visited[down] = true;
            q.emplace(down, cnt + 1);
        }
    }

    cout << "use the stairs";
}