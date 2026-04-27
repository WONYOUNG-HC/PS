#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;
using piii = pair<int, pii>;

int n, m, k;
int s, d;
int dp[1010][1010];
vector<vector<pii>> graph(1010);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    cin >> s >> d;

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;

        graph[a].push_back({w, b});
        graph[b].push_back({w, a});
    }

    fill(&dp[0][0], &dp[0][0] + 1010 * 1010, 2e9);

    //
    //
    //

    priority_queue<piii, vector<piii>, greater<piii>> pq;
    pq.push({0, {s, 0}});
    dp[s][0] = 0;

    while (!pq.empty()) {
        auto pop_q = pq.top();
        int cost = pop_q.first;
        int current = pop_q.second.first;
        int length = pop_q.second.second;
        
        pq.pop();

        if (dp[current][length] < cost || length == n - 1) {
            continue;
        }

        for (auto next : graph[current]) {
            int next_cost = next.first;
            int next_node = next.second;

            if (dp[next_node][length + 1] > cost + next_cost) {
                dp[next_node][length + 1] = cost + next_cost;
                pq.push({dp[next_node][length + 1], {next_node, length + 1}});
            }
        }
    }
    
    //
    //
    //

    cout << *min_element(dp[d] + 1, dp[d] + n) << '\n';

    for (int i = 0; i < k; i++) {
        int p;
        cin >> p;

        int answer = 2e9;
        for (int j = 1; j < n; j++) {
            dp[d][j] += j * p;

            answer = min(answer, dp[d][j]);
        }

        cout << answer << '\n';
    }
}