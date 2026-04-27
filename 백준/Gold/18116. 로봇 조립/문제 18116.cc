#include <iostream>

using namespace std;

int n;
int parent[1000010], cnt[1000010];

int find(int a) {
    if (a == parent[a]) {
        return a;
    }

    return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) {
        return;
    }

    parent[b] = a;
    cnt[a] += cnt[b];
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= 1000000; i++) {
        parent[i] = i;
        cnt[i] = 1;
    }

    for (int i = 0; i < n; i++) {
        char command; cin >> command;

        if (command == 'I') {
            int a, b;
            cin >> a >> b;

            merge(a, b);
        } else {
            int a; cin >> a;

            cout << cnt[find(a)] << '\n';
        }
    }
}