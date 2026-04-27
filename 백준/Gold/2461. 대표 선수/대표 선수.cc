#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int arr[1010][1010];
int p[1010];
int ans = 1e9;

struct cmp {
    bool operator()(int a, int b) {
        return arr[a][p[a]] > arr[b][p[b]];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }

        sort(arr[i], arr[i] + m);
    }

    //
    //
    //

    priority_queue<int, vector<int>, cmp> pq;
    int max_p = 0;
    
    for (int i = 0; i < n; i++) {
        pq.push(i);

        if (arr[i][0] > arr[max_p][0]) {
            max_p = i;
        }
    }

    while (true) {
        int min_p = pq.top();
        pq.pop();

        ans = min(ans, arr[max_p][p[max_p]] - arr[min_p][p[min_p]]);

        p[min_p] += 1;

        if (p[min_p] == m) {
            break;
        }

        if (arr[min_p][p[min_p]] > arr[max_p][p[max_p]]) {
            max_p = min_p;
        }

        pq.push(min_p);
    }

    cout << ans;
}