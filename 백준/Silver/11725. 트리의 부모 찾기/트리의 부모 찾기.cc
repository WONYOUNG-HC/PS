#include <iostream>
#include <vector>

using namespace std;

vector<int> tree[100001];
bool visited[100001];
int parent[100001];

void Dfs(int node);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int a, b;
    for (int i=0; i<n-1; i++) {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    Dfs(1);
    for (int i=2; i<=n; i++)
        cout << parent[i] << '\n';
}

void Dfs(int node) {
    visited[node] = true;

    for (int child : tree[node]){
        if (!visited[child]) {
            parent[child] = node;
            Dfs(child);
        }
    }
}