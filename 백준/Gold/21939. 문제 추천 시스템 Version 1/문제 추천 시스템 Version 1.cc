#include <iostream>
#include <set>

using namespace std;

int n, m;
set<int> arr[110];
int score[100010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int p, l;
        cin >> p >> l;

        arr[l].insert(p);
        score[p] = l;
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        string command;
        cin >> command;

        if (command == "recommend") {
            int x; cin >> x;

            if (x == -1) {
                for (int j = 1; j <= 100; j++) {
                    if (!arr[j].empty()) {
                        cout << *arr[j].begin() << '\n';
                        break;
                    }
                }
            } else {
                for (int j = 100; j >= 1; j--) {
                    if (!arr[j].empty()) {
                        cout << *(prev(arr[j].end(), 1)) << '\n';
                        break;
                    }
                }
            }
        } else if (command == "add") {
            int p, l;
            cin >> p >> l;

            arr[l].insert(p);
            score[p] = l;
        } else {
            int p, l;
            cin >> p;

            l = score[p];
            arr[l].erase(p);
        }
    }
}