#include <iostream>

using namespace std;

int n, k;
int arr[100010];
int tree[400010];

int sign(int x) {
    if (x == 0) {
        return 0;
    }

    return x / abs(x);
}

int init(int start, int end, int node) {
    if (start == end) {
        return tree[node] = arr[start];
    }

    int mid = (start + end) / 2;

    int left_value = init(start, mid, node * 2);
    int right_value = init(mid + 1, end, node * 2 + 1);

    return tree[node] = left_value * right_value;
}

int query(int start, int end, int node, int left, int right) {
    if (right < start || left > end) {
        return 1;
    }

    if (left <= start && end <= right) {
        return tree[node];
    }

    int mid = (start + end) / 2;

    int left_value = query(start, mid, node * 2, left, right);
    int right_value = query(mid + 1, end, node * 2 + 1, left, right);

    return left_value * right_value;
}

int update(int start, int end, int node, int index) {
    if (index < start || index > end) {
        return tree[node];
    }

    if (start == end) {
        return tree[node] = arr[index];
    }

    int mid = (start + end) / 2;

    int left_value = update(start, mid, node * 2, index);
    int right_value = update(mid + 1, end, node * 2 + 1, index);
 
    return tree[node] = left_value * right_value;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n >> k) {
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];

            arr[i] = sign(arr[i]);
        }

        init(1, n, 1);

        for (int i = 0; i < k; i++) {
            int a, b;
            char c;

            cin >> c >> a >> b;
            
            if (c == 'C') {
                arr[a] = sign(b);

                update(1, n, 1, a);
            } else {
                int res = query(1, n, 1, a, b);

                if (res == 1) {
                    cout << '+';
                } else if (res == -1) {
                    cout << '-';
                } else {
                    cout << 0;
                }
            }
        }

        cout << '\n';
    } 
}