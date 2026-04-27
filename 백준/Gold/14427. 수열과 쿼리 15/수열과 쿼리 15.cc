 #include <iostream>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int n, m;
int arr[100010];
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        pq.push({arr[i], i});
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        int a, b, c;

        cin >> a;

        if (a == 1) {
            cin >> b >> c;

            arr[b - 1] = c;

            pq.push({c, b - 1});
        } else {
            while (true) {
                auto [value, idx] = pq.top();

                if (arr[idx] == value) {
                    cout << idx + 1 << '\n';
                    break;
                }

                pq.pop();
            }
        }
    }
}