#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

set<int> prime_num;

void Eratosthenes(int upper = 10000);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Eratosthenes();

    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;

        pair<int, int> partition = {0, 10000};
        for (auto iter = prime_num.begin(); iter != prime_num.end(); iter++) {
            if (*iter > n / 2)
                continue;

            auto fiter = prime_num.find(n - *iter);
            if (fiter != prime_num.end()) {
                partition = {*iter, *fiter};
            }
        }

        cout << partition.first << ' ' << partition.second << '\n';
    }
}

void Eratosthenes(int upper) {
    vector<int> sieve(upper + 1, true);
    for (int i = 2; i < (int)sqrt(upper); i++) {
        if (!sieve[i])
            continue;

        int j = i * i;
        while (j <= upper) {
            sieve[j] = false;
            j += i;
        }
    }

    for (int i = 2; i <= upper; i++)
        if (sieve[i]) prime_num.insert(i);
}