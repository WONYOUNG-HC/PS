#include <iostream>
#include <vector>

#define LEFTCHILD 0
#define RIGHTCHILD 1

using namespace std;

void InOrder(vector<vector<int>>& tree, vector<int>& left, vector<int>& breadth, int node, int& x, int y);
int FindRoot(int n, vector<vector<int>>& tree);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> tree(n+1, vector<int>(2));
    for (int i=0; i<n; i++) {
        int node, left, right;
        cin >> node >> left >> right;
        tree[node][LEFTCHILD] = left;
        tree[node][RIGHTCHILD] = right;
    }

    int root = FindRoot(n, tree);
    vector<int> left(n+1);
    vector<int> breadth(n+1, 1);
    int x = 1, y = 1;
    InOrder(tree, left, breadth, root, x, y);

    int level = 0, max = 0;
    for (int i=1; i<=n; i++) {
        if (breadth[i] == 0)
            break;

        if (breadth[i] > max) {
            level = i;
            max = breadth[i];
        }
    }

    cout << level << ' ' << max;

    return 0;
}

int FindRoot(int n, vector<vector<int>>& tree) {
    vector<bool> parent(n+1, false);
    for (int i=1; i<=n; i++) {
        if (tree[i][LEFTCHILD] != -1)
            parent[tree[i][LEFTCHILD]] = true;
        if (tree[i][RIGHTCHILD] != -1)
            parent[tree[i][RIGHTCHILD]] = true;
    }

    for (int i=1; i<=n; i++) {
        if (!parent[i])
            return i;
    }

    return -1;
}

void InOrder(vector<vector<int>>& tree, vector<int>& left, vector<int>& breadth, int node, int& x, int y) {
    if (tree[node][LEFTCHILD] != -1)
        InOrder(tree, left, breadth, tree[node][LEFTCHILD], x, y+1);

    if (left[y] == 0) {
        left[y] = x;
    }
    else {
        if (breadth[y] < x - left[y] + 1)
            breadth[y] = x - left[y] + 1;
    }
    x++;

    if (tree[node][RIGHTCHILD] != -1)
        InOrder(tree, left, breadth, tree[node][RIGHTCHILD], x, y+1);
}