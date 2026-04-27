#include <iostream>
#include <cstdio>
#include <queue>
#include <set>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int graph[26][26];
bool visited[26][26] = {false};
multiset<int> ms;

void Bfs(int y, int x, int n);

int main() {
    int n;
    cin >> n;

    for (int i=1; i<n+1; i++) {
        for (int j=1; j<n+1; j++) {
            scanf("%1d", &graph[i][j]);
        }
    }

    int cnt = 0;
    for (int i=1; i<n+1; i++) {
        for (int j=1; j<n+1; j++) {
            if (graph[i][j] && !visited[i][j]) {
                Bfs(i, j, n);
                cnt++;
            }
        }
    }

    cout << cnt << '\n';
    for (int i : ms)
        cout << i << '\n';
}

void Bfs(int y, int x, int n) {
    queue<pair<int, int>> q;
    pair<int, int> pr;
    q.push(pair<int, int>(y, x));
    visited[y][x] = true;

    int cnt = 1;
    while (!q.empty()) {
        pr = q.front();
        q.pop();

        int ny, nx;
        for (int i=0; i<4; i++){
            ny = pr.first + dy[i];
            nx = pr.second + dx[i];

            if (graph[ny][nx] && !visited[ny][nx]) {
                if (ny < 1 || ny > n || nx < 1 || nx > n)
                    break;

                q.push(pair<int, int>(ny, nx));
                visited[ny][nx] = true;
                cnt++;
            }
        }
    }

    ms.insert(cnt);
}
