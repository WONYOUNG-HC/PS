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
vector<set<int>> ssc;

void DFS(int node);
void DFSInverse(set<int>& s, int node);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int v, e;
    cin >> v >> e;

    graph.resize(v + 1);
    inverse_graph.resize(v + 1);

    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        inverse_graph[b].push_back(a);
    }

    visited.resize(v + 1);
    for (int i = 1; i <= v; i++) {
        if (!visited[i])
            DFS(i);
    }

    visited.clear();
    visited.resize(v + 1);

    while (!st.empty()) {
        int node = st.top(); st.pop();
        if (visited[node])
            continue;

        set<int> s;
        DFSInverse(s, node);
        ssc.push_back(s);
    }

    sort(ssc.begin(), ssc.end());

    cout << ssc.size() << '\n';
    for (set<int>& s : ssc) {
        for (int i : s) {
            cout << i << ' ';
        }
        cout << -1 << '\n';
    }
}

void DFS(int node) {
    visited[node] = true;

    for (int next : graph[node]) {
        if (!visited[next])
            DFS(next);
    }

    st.push(node);
}

void DFSInverse(set<int>& s, int node) {
    visited[node] = true;
    s.insert(node);

    for (int next : inverse_graph[node]) {
        if (!visited[next])
            DFSInverse(s, next);
    }
}