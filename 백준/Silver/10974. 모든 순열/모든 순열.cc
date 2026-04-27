#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[10];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        arr[i] = i + 1;
    
    do {
        for (int i = 0; i < n; i++)
            cout << arr[i] << ' ';
        cout << '\n';
    } while (next_permutation(arr, arr + n));

}