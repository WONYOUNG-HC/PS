#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void Eratosthenes(int n, int k);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, b;
    cin >> a >> b;

    Eratosthenes(a, b);
    cout << -1;
}

bool isPalin(int num) {
    string str;
    while (num / 10 > 0) {
        str += (num % 10) - '0';
        num /= 10;
    }
    str += num - '0';

    int i = 0, j = str.size() - 1;
    while (i < j) {
        if (str[i] != str[j])
            return false;

        i++; j--;
    }

    return true;
}

void Eratosthenes(int a, int b) {
    vector<bool> prime_num(b + 1, true);
    prime_num[0] = false; prime_num[1] = false;

    for (int i = 2; i <= (int)sqrt(b); i++) {
        if (!prime_num[i])
            continue;

        int j = i * i;
        while (j <= b) {
            prime_num[j] = false;
            j += i;
        }
    }

    for (int i = a; i <= b; i++) {
        if (prime_num[i] && isPalin(i))
            cout << i << '\n';
    }
}
