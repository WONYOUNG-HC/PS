#include <iostream>
#include <deque>

using namespace std;

int n, m;
int structure[100010];
int c;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    deque<int> dq;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> structure[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> c;

        if (structure[i] == 0) {
            dq.push_back(c);
        }
    }

    cin >> m;

    while (m--) {
        cin >> c;

        dq.push_front(c);

        cout << dq.back() << ' ';

        dq.pop_back();
    }
}