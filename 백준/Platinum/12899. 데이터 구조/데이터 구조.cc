#include <iostream>

using namespace std;

const int mx = 2'000'000;

int n;
int arr[mx + 10];
int tree[mx * 4];

int update(int start, int end, int node, int num) {
    if (num < start || num > end) {
        return tree[node];
    }

    if (start == end) {
        return tree[node] = arr[num];
    }
    
    int mid = (start + end) / 2;

    int left_value = update(start, mid, node * 2, num);
    int rihgt_vlaue = update(mid + 1, end, node * 2 + 1, num);

    return tree[node] = left_value + rihgt_vlaue;
}

int query(int start, int end, int node, int x) {
    if (start == end) {
        return start;
    }

    int ret = 0;
    int mid = (start + end) / 2;
    int left_value = tree[node * 2];

    if (x <= left_value) {
        ret = query(start, mid, node * 2, x);
    } else {
        ret = query(mid + 1, end, node * 2 + 1, x - left_value);
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int t, x;

        cin >> t >> x;

        if (t == 1) {
            arr[x] += 1;

            update(1, mx, 1, x);
        } else {
            int value = query(1, mx, 1, x);

            cout << value << '\n';

            arr[value] -= 1;
            update(1, mx, 1, value);
        }
    }
}