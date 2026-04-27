#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

#define POS first
#define NODE second
#define DIST(tp) get<0>(tp)
#define FROM(tp) get<1>(tp)
#define TO(tp) get<2>(tp)

using namespace std;

int n;
vector<int> parent, level;
vector<pair<int, int>> pos_x, pos_y, pos_z;
vector<tuple<int, int, int>> edge;

void Init() {
    parent.resize(n + 1);
    level.resize(n + 1, 1);
    pos_x.resize(n), pos_y.resize(n), pos_z.resize(n);
    edge.reserve((n - 1) * 3);

    for (int i = 1; i <= n; i++)
        parent[i] = i;
}

int Find(int node) {
    if (node == parent[node])
        return node;

    return parent[node] = Find(parent[node]);
}

void Merge(int p, int q) {
    if(p == q)
        return;

    if (level[p] < level[q])
        swap(p, q);

    parent[q] = p;

    if (level[p] == level[q])
        level[p]++;
}

int MST() {
    int ans = 0, cnt = 0;
    for (tuple<int, int, int>& e : edge) {
        if (cnt == n)
            break;

        int dist = DIST(e);
        int x = Find(FROM(e));
        int y = Find(TO(e));

        if (x == y)
            continue;

        Merge(x, y);
        ans += dist;
        cnt++;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    Init();

    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;

        pos_x[i] = {x, i + 1};
        pos_y[i] = {y, i + 1};
        pos_z[i] = {z, i + 1};
    }

    sort(pos_x.begin(), pos_x.end());
    sort(pos_y.begin(), pos_y.end());
    sort(pos_z.begin(), pos_z.end());

    for (int i = 0; i < n - 1; i++) {
        edge.emplace_back(abs(pos_x[i].POS - pos_x[i + 1].POS), pos_x[i].NODE, pos_x[i + 1].NODE);
        edge.emplace_back(abs(pos_y[i].POS - pos_y[i + 1].POS), pos_y[i].NODE, pos_y[i + 1].NODE);
        edge.emplace_back(abs(pos_z[i].POS - pos_z[i + 1].POS), pos_z[i].NODE, pos_z[i + 1].NODE);
    }

    sort(edge.begin(), edge.end());

    cout << MST();
}