#include <iostream>

using namespace std;

int main() {
    long long s;
    cin >> s;

    long long sum = 0, n = 0;
    while (true) {
        sum += n;

        if (sum > s) {
            cout << n-1;
            return 0;
        }

        n++;
    }
}