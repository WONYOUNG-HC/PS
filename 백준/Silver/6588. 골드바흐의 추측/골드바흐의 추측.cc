#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> prime_num;

void Eratosthenes(int upper = 1000000);
void Goldbach(int n);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Eratosthenes();

    int n;
    cin >> n;
    while (n != 0) {
        Goldbach(n);
        cin >> n;
    }
}

void Eratosthenes(int upper) {
    prime_num.resize(upper + 1, true);
    for (int i = 2; i < (int)sqrt(upper); i++) {
        if (!prime_num[i])
            continue;

        int j = i * i;
        while (j <= upper) {
            prime_num[j] = false;
            j += i;
        }
    }
}

void Goldbach(int n) {
    if (n % 2)
        cout << "Goldbach's conjecture is wrong." << '\n';
    for (int i = 2; i <= n / 2; i++) {
        if (!prime_num[i])
            continue;

        if (prime_num[n - i]) {
            cout << n << " = " << i << " + " << n - i << '\n';
            return;
        }
    }

}