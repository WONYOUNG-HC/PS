#include <iostream>
#include <vector>

using namespace std;

vector<int> tree[50];
int cnt;

void Dfs(int node);

int main() {
    int n;
    cin >> n;

    int input[n];
    for (int& i : input)
        cin >> i;
    int c;
    cin >> c;

    int root = -1;
    for (int i=0; i<n; i++) {
        if (input[i] == c || i == c) continue;

        if (input[i] == -1)
            root = i;
        else
            tree[input[i]].push_back(i);
    }

    if (root != -1) Dfs(root);
    cout << cnt;
}

void Dfs(int node) {
    if (tree[node].empty()) {
        cnt++;
        return;
    }

    for (int child : tree[node])
        Dfs(child);
}