#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[1010];
int in[1010];
int de[1010];
int bi[1010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        in[i] = 1;

        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                in[i] = max(in[i], in[j] + 1);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        de[n - i - 1] = 1;

        for (int j = 0; j < i; j++) {
            if (arr[n - i - 1] > arr[n - j - 1]) {
                de[n - i - 1] = max(de[n - i - 1], de[n - j - 1] + 1);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        bi[i] = in[i] + de[i] - 1;
    }

    cout << *max_element(bi, bi + n);
}