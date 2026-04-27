#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int arr[10];
priority_queue<int> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int t;

        cin >> t;

        pq.push(t);
    }

    int cur = 0;
    int rest = m;

    while (!pq.empty()) {
        int item = pq.top();
        pq.pop();

        if (rest == 0) {
            int end_time = *min_element(arr, arr + m);

            cur += end_time;

            for (int i = 0; i < m; i++) {
                arr[i] -= end_time;

                if (arr[i] == 0) {
                    rest += 1;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            if (arr[i] == 0) {
                arr[i] = item;
                rest -= 1;

                break;
            }
        }
    }


    cout << cur + *max_element(arr, arr + m);
}