#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> adj[1011];
int match[1011];
bool vis[1011];

bool dfs(int x) {
	if (vis[x])
		return false;
	vis[x] = true;
		
	for (int y : adj[x]) {
		if (match[y] == 0 || dfs(match[y])) {
			match[y] = x;
			return true;
		}
	}
	
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		int c; cin >> c;
		
		for (int j = 0; j < c; j++) {
			int w; cin >> w;
			adj[i].push_back(w);
		}
	}
	
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 2; j++) {
			fill_n(vis, n + 10, false);
			
			if (dfs(i)) ans++;
		}
	}
	
	cout << ans;
}