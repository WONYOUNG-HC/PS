#include <iostream>
#include <vector>

#define INF 0x3fffffff

using namespace std;

void Floyd(int n, vector<vector<int>>& graph, vector<vector<int>>& path);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n+1, vector<int>(n+1, INF));
    for (int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = c;
        graph[b][a] = c;
    }

    vector<vector<int>> path(n+1, vector<int>(n+1));
    Floyd(n, graph, path);

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (i == j) {
                cout << "- ";
            }
            else {
                int p = j;
                while (p != path[i][p]) p = path[i][p];
                cout << p << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}

void Floyd(int n, vector<vector<int>>& graph, vector<vector<int>>& path) {
    for (int i=1; i<=n; i++) {
        graph[i][i] = 0;
        for (int j=1; j<=n; j++) {
            if (graph[i][j] != INF)
                path[i][j] = j;
        }
    }

    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if (graph[i][j] > graph[i][k] + graph[k][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                    path[i][j] = k;
                }
            }
        }
    }
}