#include <iostream>
#include <vector>
#include <stack>
#include <set>

using namespace std;

int n, m, id, ans;
set<int> adj[100010];
stack<int> s;
int ind[100010];
int p[100010];
bool finish[100010];

int dfs(int x) {
    p[x] = ++id;
    s.push(x);

    int parent = p[x];
    for (int y : adj[x]) {
        if (p[y] == 0)
            parent = min(parent, dfs(y));
        else if (!finish[y]) {
            parent = min(parent, p[y]);
            ind[y]--;
        }
    }

    if (parent == p[x]) {
        vector<int> scc;
        while (true) {
            int t = s.top();
            s.pop();
            finish[t] = true; 
            scc.push_back(t);

            if (t == x)
                break;
            ind[t]--;
        }

        if (scc.size() > 1) {
            bool flag = true;
            for (int t : scc)
                ind[t] > 0 && (flag = false);  
            flag && ans++;
        }
    }

    return parent;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        
        adj[a].insert(b);
        ind[b]++;
    }

    for (int i = 0; i < n; i++)
        if (ind[i] == 0) ans++;

    for (int i = 0; i < n; i++)
        if (!finish[i]) dfs(i);


    cout << ans;
}