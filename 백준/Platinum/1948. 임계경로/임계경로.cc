#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int n, m;
vector<pii> graph[10010];
int dist[10010];
set<int> parent[10010];
int source, target;
set<pii> edge;

void f(int x) {
    for (int y : parent[x]) {
        if (edge.find({x, y}) == edge.end()) {
            edge.insert({x, y});
            f(y);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b, c;

        cin >> a >> b >> c;
        
        graph[a].push_back({c, b});
    }

    cin >> source >> target;

    //
    //
    //

    fill_n(dist, n + 10, -1);

    priority_queue<pii> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int node, cost;

        tie(cost, node) = pq.top();
        pq.pop();

        for (auto next : graph[node]) {
            int next_node, next_cost;

            tie(next_cost, next_node) = next;

            if (dist[next_node] > dist[node] + next_cost) {
                continue;
            }

            if (dist[next_node] == dist[node] + next_cost && parent[next_node].find(node) != parent[next_node].end()) {
                continue;
            }

            if (dist[next_node] < dist[node] + next_cost) {
                parent[next_node].clear();
            }

            dist[next_node] = dist[node] + next_cost;
            parent[next_node].insert(node);

            pq.push({dist[next_node], next_node});
        }
    }

    f(target);

    cout << dist[target] << '\n' << edge.size();
}