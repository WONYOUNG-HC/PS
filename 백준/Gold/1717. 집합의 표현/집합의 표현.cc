#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;
vector<int> level;

void Init(int n);
void Union(int a, int b);
bool Equal(int a, int b);


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    Init(n);
    for (int i=0; i<m; i++) {
        int order, a, b;
        cin >> order >> a >> b;

        if (order == 0)
            Union(a, b);
        else if (Equal(a, b))
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }

    return 0;
}

void Init(int n) {
    level.resize(n+1, 1);
    parent.resize(n+1);
    for (int i=0; i<=n; i++)
        parent[i] = i;
}

int Find(int i) {
    if (i == parent[i])
        return i;

    return Find(parent[i]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    if (a == b)
        return;

    if (level[a] > level[b])
        swap(a, b);
    parent[a] = b;

    if (level[a] == level[b])
        level[b]++;
}

bool Equal(int a, int b) {
    if (Find(a) == Find(b))
        return true;
    else
        return false;
}