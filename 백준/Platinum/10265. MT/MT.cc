#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<vector<int>> inverse_graph;
vector<bool> visited;
stack<int> st;
vector<pair<int, int>> person;

void DFS(int node);
void DFSInverse(set<int>& ssc, int node);
void OutDegree(set<int>& ssc, int& out, int node);
int Knapsack(int k);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    graph.resize(n + 1);
    inverse_graph.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        graph[i].push_back(x);
        inverse_graph[x].push_back(i);
    }

    visited.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        if (!visited[i])
            DFS(i);
    }

    visited.clear();
    visited.resize(n + 1);

    while (!st.empty()) {
        int node = st.top(); st.pop();
        if (visited[node])
            continue;

        set<int> ssc;
        DFSInverse(ssc, node);

        if (ssc.size() == 1 && graph[node].front() != node)
            continue;
        if (ssc.size() > k)
            continue;

        int out = 0;
        for (int v : ssc) {
            for (int o : inverse_graph[v]) {
                if (ssc.find(o) == ssc.end())
                    OutDegree(ssc, out, o);
            }
        }

        person.emplace_back(ssc.size(), out);
    }

    cout << Knapsack(k);
}

void DFS(int node) {
    visited[node] = true;

    for (int next : graph[node]) {
        if (!visited[next])
            DFS(next);
    }

    st.push(node);
}

void DFSInverse(set<int>& ssc, int node) {
    visited[node] = true;
    ssc.insert(node);

    for (int next : inverse_graph[node]) {
        if (!visited[next])
            DFSInverse(ssc, next);
    }
}

void OutDegree(set<int>& ssc, int& out, int node) {
    out++;

    for (int o : inverse_graph[node]) {
        if (ssc.find(o) == ssc.end())
            OutDegree(ssc, out, o);
    }
}

int Knapsack(int k) {
    int m = (int)person.size();
    vector<vector<int>> dp(m + 1, vector<int>(k + 1));

    for (int i = 1; i <= m; i++) {
        int ssc = person[i - 1].first;
        int out = person[i - 1].second;

        for (int j = 1; j <= k; j++) {
            dp[i][j] = dp[i - 1][j];

            if (ssc > j)
                continue;

            for (int l = 0; l <= out; l++) {
                if (ssc + l > j)
                    break;

                dp[i][j] = max(dp[i][j], dp[i - 1][j - (ssc + l)] + (ssc + l));
            }
        }
    }

    return dp[m][k];
}