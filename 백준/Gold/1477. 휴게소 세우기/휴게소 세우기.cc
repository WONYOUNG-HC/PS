#include <iostream>
#include <set>

using namespace std;

int n, m, l;
int arr[60];

bool decision(int mid) {
    set<int> points(arr, arr + n);

    int start = 0;
    int install = 0;

    for (int i = 1; i < l; i++) {
        if (points.find(i) != points.end()) {
            start = i;
            
            continue;
        }

        if (i - start == mid) {
            install += 1;
            start = i;

            if (install > m) {
                return false;
            }
        }
    }

    return l - start <= mid && install <= m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> l;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int left = 0;
    int right = 1000;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (decision(mid)) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << left;
}