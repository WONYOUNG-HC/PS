#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[510];
int lis[510];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        
        cin >> a >> b;

        arr[a] = b;
    }

    fill_n(lis, 510, 1);
    
    for (int i = 1; i <= 500; i++) {
        for (int j = 1; j < i; j++) {
            if (arr[i] == 0 || arr[j] == 0) {
                continue;
            }

            if (arr[i] > arr[j]) {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
    }

    int lis_len = *max_element(lis, lis + 500);

    cout << n - lis_len;
}