#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void Prim(int n, vector<vector<int>>& matrix, vector<vector<int>>& list);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> matrix(n+1, vector<int>(n+1));
    for (int i=1; i<n; i++) {
        for (int j=i+1; j<=n; j++) {
            cin >> matrix[i][j];
            matrix[j][i] = matrix[i][j];
        }
    }

    vector<vector<int>> list(n+1);
    Prim(n, matrix, list);

    for (int i=1; i<=n; i++) {
        cout << list[i].size() << ' ';
        for (int j : list[i])
            cout << j << ' ';
        cout << '\n';
    }

    return 0;
}

void Prim(int n, vector<vector<int>>& matrix, vector<vector<int>>& list) {
    vector<bool> visited(n+1, false);
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    for (int i=2; i<=n; i++)
        pq.emplace(matrix[1][i], 1, i);
    visited[1] = true;
    int cnt = 1;

    while (cnt != n) {
        int from = get<1>(pq.top());
        int to = get<2>(pq.top());
        pq.pop();

        if (visited[to])
            continue;

        cnt++;
        visited[to] = true;
        list[from].push_back(to);
        list[to].push_back(from);

        for (int i=2; i<=n; i++) {
            if (i != to && !visited[i])
                pq.emplace(matrix[to][i], to, i);
        }
    }

    for (int i=1; i<=n; i++)
        sort(list[i].begin(), list[i].end());
}