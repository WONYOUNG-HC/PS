#include <iostream>
#include <algorithm>
#include <tuple>

#define ti tuple<int, int, int, int>

using namespace std;

int n, k;
ti arr[1010];

bool operator==(const ti& left, const ti& right) {
    return get<0>(left) == get<0>(right) && get<1>(left) == get<1>(right) && get<2>(left) == get<2>(right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        arr[a] = {b, c, d, a};
    }

    sort(arr, arr + n + 1, greater<>());

    int idx = 0;
    while (get<3>(arr[idx]) != k) idx++;
    while (idx > 0 && arr[idx - 1] == arr[idx]) idx--;

    cout << idx + 1;
}