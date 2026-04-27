#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<bool> sieve(5000001, true);
vector<int> prime_num;

void Eratosthenes(int upper = 5000000);
void Factorization(int num);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    Eratosthenes();

    for (int i=0; i<n; i++) {
        int num;
        cin >> num;
        Factorization(num);
    }
}

void Eratosthenes(int upper) {
    for (int i=2; i<=sqrt(upper); i++) {
        if (!sieve[i])
            continue;

        int j = i + i;
        while (j <= upper) {
            sieve[j] = false;
            j += i;
        }
    }

    for (int i=2; i<=upper; i++) {
        if (sieve[i])
            prime_num.push_back(i);
    }
}

void Factorization(int num) {
    vector<int> fact;

    int i=0;
    while (num != 1) {
        if (num % prime_num[i] == 0) {
            num /= prime_num[i];
            cout << prime_num[i] << ' ';
        }
        else {
            i++;
        }

        if (sieve[num]) {
            cout << num;
            break;
        }
    }

    cout << '\n';
}