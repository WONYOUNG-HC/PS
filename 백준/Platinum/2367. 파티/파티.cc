#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int SOURCE = 0;
const int TARGET = 401;
const int OFFSET = 300;

int n, k, d;
vector<int> graph[410];
int cap[410][410];
int flow[410][410];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k >> d;

    for (int i = 1; i <= d; i++) {
        int cnt;

        cin >> cnt;

        graph[OFFSET + i].push_back(TARGET);
        graph[TARGET].push_back(OFFSET + i);
        cap[OFFSET + i][TARGET] = cnt;
    }

    for (int i = 1; i <= n; i++) {
        int cnt;

        cin >> cnt;

        for (int j = 0; j < cnt; j++) {
            int food;

            cin >> food;

            graph[i].push_back(OFFSET + food);
            graph[OFFSET + food].push_back(i);
            cap[i][OFFSET + food] = 1;
        }

        graph[SOURCE].push_back(i);
        graph[i].push_back(SOURCE);
        cap[SOURCE][i] = k;
    }

    //
    //
    //

    int ans = 0;

    while (true) {
        queue<int> q;
        int prev[410];

        fill(prev, prev + 410, -1);
        q.push(SOURCE);

        while (!q.empty()) {
            int cur = q.front();

            q.pop();

            for (int next : graph[cur]) {
                if (prev[next] == -1 && cap[cur][next] - flow[cur][next] > 0) {
                    prev[next] = cur;
                    q.push(next);
                }
            }
        }

        if (prev[TARGET] == -1) {
            break;
        }

        int node = TARGET;

        while (node != SOURCE) {
            flow[prev[node]][node] += 1;
            flow[node][prev[node]] -= 1;

            node = prev[node];
        }

        ans += 1;
    }

    cout << ans;
}