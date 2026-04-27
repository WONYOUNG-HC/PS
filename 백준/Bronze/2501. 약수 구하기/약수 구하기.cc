#include <iostream>

using namespace std;

int n, k;
int arr[10010];

int main() {
    cin >> n >> k;

    int idx = 0;
    for (int i = 1; i <= n; i++)
        n % i == 0 && (arr[idx++] = i);
    
    cout << arr[k - 1];
}