#include <iostream>
#include <array>

using namespace std;

int n, vis, ans;
pair<int, int> tree[100010];

void in_order(int x) {
    if (x == -1) {
        ans--;
        return;
    }
    
    in_order(tree[x].first);
    vis++;
    in_order(tree[x].second);

    ans += 2;
    if (vis < n)
        ans++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        tree[a] = {b, c};
    }

    in_order(1);
    cout << ans;
}