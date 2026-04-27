#include <iostream>

using namespace std;

long long x, y, z;

int main() {
    cin >> x >> y;

    z = y * 100 / x;
    
    if(z >= 99) {
        cout << -1;
        return 0;
    } 

    int left = 0, right= 1e9;

    while(left <= right) {
        int mid = (left + right) / 2;

        long long rate = (y + mid) * 100 / (x + mid);

        if (z < rate) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    cout << left;
}