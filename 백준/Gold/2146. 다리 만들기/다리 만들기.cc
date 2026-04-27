#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1e9

using namespace std;

int n, land;
int graph[111][111], island[111][111];
vector<pair<int, int>> bound[10000];
bool vis[111][111];
bool chk[111];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	fill_n(&graph[0][0], 111 * 111, -1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> graph[i][j];
		}
	}
	
	land = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (graph[i][j] == 1 && island[i][j] == 0) {
				queue<pair<int, int>> q;
				q.emplace(i, j);
				island[i][j] = land;
				
				while (!q.empty()) {
					int y = q.front().first;
					int x = q.front().second;
					q.pop();
					
					for (int* d : dir) {
						int dy = y + d[0];
						int dx = x + d[1];
						
						if (graph[dy][dx] == -1) {
							continue;
						}
						else if (graph[dy][dx] == 1 && island[dy][dx] == 0) {
							island[dy][dx] = land;
							q.emplace(dy, dx);
						}
						else if (graph[dy][dx] == 0 && !vis[y][x]) {
							bound[land].emplace_back(y, x);
							vis[y][x] = true;
						}
					}
				}
				
				land++;
			}
		}
	}
	/*
	cout << '\n';
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << vis[i][j] << ' ';
		}
		cout << '\n';
	}
	*/
	int ans = INF;
	for (int i = 1; i < land; i++) {
		int dist[111][111];
		fill_n(&dist[0][0], 111 * 111, INF);
		queue<pair<int, int>> q;
		
		for (pair<int, int> pr : bound[i]) {
			q.push(pr);
			dist[pr.first][pr.second] = 0;
		}
		
		while (!q.empty()) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			
			for (int* d : dir) {
				int dy = y + d[0];
				int dx = x + d[1];
				
				if (graph[dy][dx] == -1) {
					continue;
				}
				else if (graph[dy][dx] == 0 && dist[dy][dx] > dist[y][x] + 1) {
					dist[dy][dx] = dist[y][x] + 1;
					q.emplace(dy, dx);
				}
				else if (graph[dy][dx] == 1 && island[dy][dx] != i) {
					ans = min(ans, dist[y][x]);
				}
			}
		}
	}
	
	cout << ans;
}

/*
test 1
10
1 1 1 0 0 0 0 1 1 1
1 1 1 1 0 0 0 0 1 1
1 0 1 1 0 0 0 0 1 1
0 0 1 1 1 0 0 0 0 1
0 0 0 1 0 0 0 0 0 1
0 0 0 0 0 0 0 0 0 1
0 0 0 0 0 0 0 0 0 0 
0 0 0 0 1 1 0 0 0 0
0 0 0 0 1 1 1 0 0 0
0 0 0 0 0 0 0 0 0 0 

3

test 2
8
1 1 1 0 0 0 0 0
1 0 1 0 0 0 0 0
0 0 1 0 0 0 0 0
0 0 1 0 0 0 0 0
0 0 1 0 0 0 0 1
0 0 0 0 0 0 1 1
0 0 0 0 1 0 1 0
0 0 0 0 1 1 1 0

3

test 3
5
1 0 0 0 0
0 0 0 0 0
0 0 1 0 0
0 0 0 0 1
0 0 0 0 1

2

test 4
5
1 0 0 0 0
1 0 0 0 1
1 1 1 0 1
0 0 0 0 0
0 0 0 1 0

1

test 5
5
1 0 0 0 1
0 0 0 1 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0 

1

test 6
6
1 1 0 1 0 0
0 0 0 1 0 1
0 0 1 1 0 0
1 1 0 0 0 1
1 1 1 0 1 1
0 1 1 1 1 0

1
*/
