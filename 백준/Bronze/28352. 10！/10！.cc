#include <iostream>

using namespace std;

int main() {
    long long n; cin >> n;

    long long fac = 1;
    for (long long i = 2; i <= n; i++)
        fac *= i;

    cout << fac / (60 * 60 * 24 * 7);
}