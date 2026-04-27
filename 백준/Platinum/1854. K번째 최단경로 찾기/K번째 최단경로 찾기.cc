#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, k;
vector<pair<int, int> > graph[1010];
priority_queue<int> dist[1010]; 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> k;
	
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		
		graph[a].emplace_back(c, b);
	}
	
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	pq.emplace(0, 1);
	dist[1].push(0);
	
	while (!pq.empty()) {
		int cost = pq.top().first;
		int node = pq.top().second;
		pq.pop();
		
		for (auto& pr : graph[node]) {
			int next_cost = pr.first;
			int next_node = pr.second;
			
			if (dist[next_node].size() < k) {
				dist[next_node].push(next_cost + cost);
				pq.emplace(next_cost + cost, next_node);
			}
			else if (dist[next_node].top() > next_cost + cost) {
				dist[next_node].pop();
				dist[next_node].push(next_cost + cost);
				pq.emplace(next_cost + cost, next_node);
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		if (dist[i].size() < k)
			cout << -1 << '\n';
		else
			cout << dist[i].top() << '\n';
	}
}