#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int n, m;
vector<pii> adj[1010];
int dist[1010];
int cnt[1010];
int prv[1010];
set<pii> ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        
        adj[a].emplace_back(c, b);
        adj[b].emplace_back(c, a);
    }

    fill_n(dist, 1010, 1e9);
    priority_queue<pii, vector<pii>, greater<>> pq;
    pq.emplace(0, 1);
    dist[1] = 0;

    while (!pq.empty()) {
        pii x = pq.top();
        pq.pop();

        if (dist[x.second] < x.first)
            continue;
        
        for (pii y : adj[x.second]) {
            if (dist[y.second] > x.first + y.first) {
                dist[y.second] = x.first + y.first;
                pq.emplace(dist[y.second], y.second);

                prv[y.second] = x.second;
                cnt[y.second] = cnt[x.second] + 1;
            }
            else if (dist[y.second] == x.first + y.first) {
                if (cnt[y.second] > cnt[x.second] + 1) {
                    prv[y.second] = x.second;
                    cnt[y.second] = cnt[x.second] + 1;
                }
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        int cur = i;
        while (cur != 1) {
            int pr = prv[cur];
            if (ans.find({min(cur, pr), max(cur, pr)}) != ans.end()) 
                break;
            
            ans.emplace(min(cur, pr), max(cur, pr));
            cur = pr;
        }
    }

    cout << ans.size() << '\n';
    for (pii pr : ans) {
        cout << pr.first << ' ' << pr.second << '\n';
    }
}