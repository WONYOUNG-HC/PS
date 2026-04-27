#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int n, p, k;
vector<pii> graph[1010];
int cnt[1010];

bool decision(int mid) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    fill_n(cnt, 1010, 1e9);
    
    cnt[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        int pass, cur;
        tie(pass, cur) = pq.top();
        
        pq.pop();

        if (pass > cnt[cur]) {
            continue;
        }

        for (pii next : graph[cur]) {
            int next_cost, next_node;
            tie(next_cost, next_node) = next;

            if (next_cost <= mid && cnt[next_node] > pass) {
                cnt[next_node] = pass;
                pq.push({pass, next_node});
            } else if (next_cost > mid && cnt[next_node] > pass + 1) {
                cnt[next_node] = pass + 1;
                pq.push({pass + 1, next_node});
            }
        }
    }

    return cnt[n] <= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> p >> k;

    for (int i = 0; i < p; i++) {
        int a, b, c;

        cin >> a >> b >> c;

        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }

    //
    //
    //

    int left = 0;
    int right = 1e9;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (decision(mid)) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    int ans = (left > 1e9 ? -1 : left);

    cout << ans;
}