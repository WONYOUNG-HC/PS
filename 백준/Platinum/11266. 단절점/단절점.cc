#include <iostream>
#include <vector>

using namespace std;

int v, e;
vector<int> graph[10010];
int discover[10010];
bool cut[10010];
int cnt = 1;

int find_cut(int cur, int is_root) {
    int ret = cnt;
    int child = 0;

    discover[cur] = cnt;
    cnt += 1;

    for (int next : graph[cur]) {
        if (discover[next] == 0) {
            int subtree = find_cut(next, false);

            child += 1;

            if (!is_root && subtree >= discover[cur]) {
                cut[cur] = true;
            }

            ret = min(ret, subtree);
        } else {
            ret = min(ret, discover[next]);
        }
    }

    if (is_root && child >= 2) {
        cut[cur] = true;
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> v >> e;

    for (int i = 0; i < e; i++) {
        int a, b;

        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> ans;

    for (int i = 1; i <= v; i++) {
        if (discover[i] == 0) {
            find_cut(i, true);
        }
    }

    for (int i = 1; i <= v; i++) {
        if (cut[i]) {
            ans.push_back(i);
        }
    }

    cout << ans.size() << '\n';
    
    for (int x : ans) {
        cout << x << ' ';
    }
}