#include <iostream>
#include <algorithm>

using namespace std;

int n, c;
int arr[200000];

int BinarySearch(int low, int high);
bool Decision(int dist);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> c;
    for (int i=0; i<n; i++)
        cin >> arr[i];

    sort(arr, arr+n);
    int d = arr[0] - 1;
    for (int i=1; i<n; i++)
        arr[i] -= d;
    arr[0] = 1;

    cout << BinarySearch(arr[0], arr[n-1]);
}

int BinarySearch(int low, int high) {
    int mid;
    while (true) {
        mid = (low + high) / 2;
        if (Decision(mid)) {
            if (high == mid) break;
            high = mid;
        }
        else {
            if (low == mid) break;
            low = mid;
        }
    }
    return mid;
}

bool Decision(int dist) {
    int router;
    router = arr[0];

    int i=1, j=1;
    while (i < n && j < c) {
        if (arr[i] - router >= dist) {
            router = arr[i];
            j++;
        }
        i++;
    }

    if (i == n && j < c)
        return true;
    else
        return false;
}