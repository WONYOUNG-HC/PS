#include <iostream>
#include <queue>
#include <set>

using namespace std;

string str;
int k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> str >> k;

    queue<pair<int, string>> q;
    set<pair<int, string>> vis;

    vis.insert({0, str});
    q.push({0, str});

    while (!q.empty()) {
        auto [cnt, cur] = q.front();
        q.pop();

        if (cnt == k) {
            continue;
        }

        for (int i = 0; i < cur.size(); i++) {
            for (int j = i + 1; j < cur.size(); j++) {
                swap(cur[i], cur[j]);

                if (vis.find({cnt + 1, cur}) == vis.end() && cur[0] != '0') {
                    vis.insert({cnt + 1, cur});
                    q.push({cnt + 1, cur});
                }

                swap(cur[i], cur[j]);
            }
        }
    }

    if ((*(--vis.end())).first == k) {
        cout << (*(--vis.end())).second;
    } else {
        cout << -1;
    }
}