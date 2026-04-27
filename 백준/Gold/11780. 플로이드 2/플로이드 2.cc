#include <iostream>
#include <vector>
#include <algorithm>

#define INF 0x2fff

using namespace std;

int n;
int graph[101][101];
int path[101][101];

void Floyd();
void ShowPath(int i, int j);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> n >> m;

    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            if (i != j) graph[i][j] = INF;

    int a, b, c;
    for (int i=0; i<m; i++) {
        cin >> a >> b >> c;
        graph[a][b] = min(c, graph[a][b]);
    }

    Floyd();

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            graph[i][j] == INF ? cout << 0 << ' ' : cout << graph[i][j] << ' ';
        }
        cout << '\n';
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            ShowPath(i, j);
        }
    }
}

void Floyd() {
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                int cost = graph[i][k] + graph[k][j];
                if (cost < graph[i][j]) {
                    graph[i][j] = cost;
                    path[i][j] = k;
                }
            }
        }
    }
}

void TracePath(int i, int j, vector<int>& v) {
    if (!path[i][j])
        return;

    TracePath(i, path[i][j], v);
    v.push_back(path[i][j]);
    TracePath(path[i][j], j, v);
}

void ShowPath(int i, int j) {
    if (i == j || graph[i][j] == INF) {
        cout << "0 \n";
        return;
    }

    vector<int> v;
    v.push_back(i);
    TracePath(i, j, v);
    v.push_back(j);

    cout << v.size() << ' ';
    for (int p : v)
        cout << p << ' ';
    cout << '\n';
}