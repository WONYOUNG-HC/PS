#include <iostream>
#include <vector>
#include <algorithm>

#define INF 0x3fffffff

using namespace std;

int n;
int w[10][10];

int Dfs(int node, int dist, vector<int> path);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin >> w[i][j];

    vector<int> path;
    cout << Dfs(0, 0, path);
}

int Dfs(int node, int dist, vector<int> path) {
    if (path.size()+1 == n) {
        if (w[node][0]) return dist + w[node][0];
        else return INF;
    }

    path.push_back(node);
    vector<int> cost(1, INF);
    for (int j=0; j<n; j++) {
        if (!w[node][j]) continue;
        if (find(path.begin(), path.end(), j) != path.end()) continue;

        cost.push_back(Dfs(j, dist+w[node][j], path));
    }

    return *min_element(cost.begin(), cost.end());
}