#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> tree[100001];
bool visited[100001];
int dp[100001];
int diameter;

void Dfs(int node);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int parent, child, cost;
    for (int i=0; i<n; i++) {
        cin >> parent >> child;
        while (child != -1) {
            cin >> cost;
            tree[parent].emplace_back(child, cost);
            cin >> child;
        }
    }

    Dfs(1);
    cout << diameter;
}

void Dfs(int node) {
    visited[node] = true;
    if (tree[node].empty())
        return;

    vector<int> cost;
    for (const pair<int, int>& pr : tree[node]) {
        if (!visited[pr.first]) {
            Dfs(pr.first);
            cost.push_back(dp[pr.first] + pr.second);
        }
    }
    cost.push_back(0);

    sort(cost.begin(), cost.end(), greater<>());
    dp[node] = cost[0];
    diameter = max(diameter, cost[0]+cost[1]);
}