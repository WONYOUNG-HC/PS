#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> tree[10001];
int dp[10001];
int diameter;

void Dfs(int node);

int main() {
    int n;
    cin >> n;

    int parent, child, cost;
    for (int i=0; i<n-1; i++) {
        cin >> parent >> child >> cost;
        tree[parent].emplace_back(child, cost);
    }

    Dfs(1);
    cout << diameter;
}

void Dfs(int node) {
    if (tree[node].empty())
        return;

    vector<int> cost;
    for (const pair<int, int>& pr : tree[node]) {
        Dfs(pr.first);
        cost.push_back(dp[pr.first] + pr.second);
    }
    cost.push_back(0);

    sort(cost.begin(), cost.end(), greater<>());
    dp[node] = cost[0];
    diameter = max(diameter, cost[0]+cost[1]);
}