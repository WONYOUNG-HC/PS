#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    vector<int> in_degree(n + 1);
    vector<int> semester(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        in_degree[b]++;
    }

    vector<int> v;
    for (int i = 1; i <= n; i++)
        if (in_degree[i] == 0) v.push_back(i);

    int count = 1;
    while (!v.empty()) {
        for (int lecture : v) {
            for (int next : graph[lecture])
                in_degree[next]--;

            semester[lecture] = count;
            in_degree[lecture]--;
        }
        count++;

        v.clear();

        for (int i = 1; i <= n; i++)
            if (in_degree[i] == 0) v.push_back(i);
    }

    for (int i = 1; i <= n; i++)
        cout << semester[i] << ' ';
}