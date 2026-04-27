#include <iostream>

using namespace std;

int n;
int tree[4000010];

int query(int start, int end, int node, int value) {
    if (start == end)
        return start;

    int left_cnt = tree[node * 2];
    
    int mid = (start + end) / 2;
    if (value <= left_cnt) 
        return query(start, mid, node * 2, value);
    else 
        return query(mid + 1, end, node * 2 + 1, value - left_cnt);
}

int update(int start, int end, int node, int index, int value) {
    if (end < index || start > index)
        return tree[node];
    
    if (start == end)
        return tree[node] += value;
    
    int mid = (start + end) / 2;
    return tree[node] = update(start, mid, node * 2, index, value) + update(mid + 1, end, node * 2 + 1, index, value);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a;

        if (a == 1) {
            cin >> b;
            c = query(1, 1000000, 1, b);
            cout << c << '\n';
            update(1, 1000000, 1, c, -1);
        }
        else {
            cin >> b >> c;
            update(1, 1000000, 1, b, c);
        }
    }
}