#include <iostream>
#include <cmath>

using namespace std;

bool isPalin(int n);
bool isPrime(int n);

int main() {
    int n; cin >> n;

    while (true) {
        if (isPalin(n) && isPrime(n)) {
            cout << n;
            break;
        }

        n++;
    }
}

bool isPalin(int n) {
    string str;

    while (n / 10 != 0) {
        str += ((n % 10) - 48);
        n /= 10;
    }
    str += n - 48;

    int i = 0, j = (int)str.size() - 1;
    while (i < j) {
        if (str[i] != str[j])
            return false;

        i++; j--;
    }

    return true;
}

bool isPrime(int n) {
    if (n == 1)
        return false;

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}