#include <iostream>
#include <vector>
#include <set>

using namespace std;

int v, e;
vector<int> graph[100010];
int discover[100010];
set<pair<int, int>> cut;

int find_cut(int cur, int parent, int &discover_time) {
    int ret = discover[cur] = discover_time;

    discover_time += 1;

    for (int next : graph[cur]) {
        if (discover[next] == 0) {
            int sub_tree = find_cut(next, cur, discover_time);

            if (sub_tree > discover[cur]) {
                cut.insert({min(cur, next), max(cur, next)});
            }

            ret = min(ret, sub_tree);
        } else if (next != parent) {
            ret = min(ret, discover[next]);
        }
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

    //
    //
    //

    int discover_time = 1;

    for (int i = 1; i <= v; i++) {
        if (discover[i] == 0) {
            find_cut(i, 0, discover_time);
        }
    }

    //
    //
    //

    cout << cut.size() << '\n';

    for (auto edge : cut) {
        cout << edge.first << ' ' << edge.second << '\n';
    }
}