#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> inorder;
vector<int> postorder;
int tree[100010][2];

int f(int begin, int end) {
    if (begin > end) {
        return 0;
    }

    int root = postorder.back();
    postorder.pop_back();

    int index = find(inorder.begin(), inorder.end(), root) - inorder.begin();
    int right = f(index + 1, end);
    int left = f(begin, index - 1);

    tree[root][0] = left;
    tree[root][1] = right;

    return root;
}

void preorder(int cur) {
    if (cur == 0) {
        return;
    }

    cout << cur << ' ';
    preorder(tree[cur][0]);
    preorder(tree[cur][1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    inorder.resize(n);
    postorder.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> postorder[i];
    }

    int root = f(0, n - 1);

    preorder(root);
}