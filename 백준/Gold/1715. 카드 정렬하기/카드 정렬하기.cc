#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<>> pq;
    int input;
    for (int i=0; i<n; i++) {
        cin >> input;
        pq.push(input);
    }

    int cnt = 0;
    while (pq.size() != 1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();

        cnt += (a + b);
        pq.push(a+b);
    }

    cout << cnt;
}