#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int arr[510];
bool graph[510][510];
int indegree[510];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;

    cin >> tc;

    while (tc--) {
        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }

        fill_n(&graph[0][0], 510 * 510, false);
        fill_n(indegree, 510, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                graph[arr[i]][arr[j]] = true;
                indegree[arr[j]] += 1;
            }
        }

        cin >> m;

        for (int i = 0; i < m; i++) {
            int a, b;

            cin >> a >> b;

            if (!graph[a][b]) {
                swap(a, b);
            }

            swap(graph[a][b], graph[b][a]);
            indegree[a] += 1;
            indegree[b] -= 1;
        }

        //
        //
        //

        vector<int> ans;
        queue<int> q;
        bool ambiguos = false;

        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int cur = q.front();
            
            q.pop();

            if (q.size() > 0) {
                ambiguos = true;

                break;
            }

            ans.push_back(cur);

            for (int i = 1; i <= n; i++) {
                if (graph[cur][i]) {
                    indegree[i] -= 1;

                    if (indegree[i] == 0) {
                        q.push(i);
                    }
                }
            } 
        }

        //
        //
        //

        if (ambiguos) {
            cout << "?" << '\n';
        } else if (ans.size() < n) {
            cout << "IMPOSSIBLE" << '\n';
        } else {
            for (auto it = ans.begin(); it < ans.end(); it++) {
                cout << *it << ' ';
            }
            cout << '\n';
        }
    }
}