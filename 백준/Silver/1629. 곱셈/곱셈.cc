#include <iostream>

using namespace std;

long long Power(int a, int b, int c) {
    if (b == 1)
        return a % c;

    if (b % 2 == 0)
        return (Power(a, b/2, c) * Power(a, b/2, c)) % c;
    else
        return (((Power(a, (b-1)/2, c) * Power(a, (b-1)/2, c))%c) * (a%c)) % c;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    cout << Power(a, b, c);
}