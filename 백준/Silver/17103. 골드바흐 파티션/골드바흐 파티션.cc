#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> prime_num;

void Eratosthenes(int upper = 1000000);
int Goldbach(int n);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Eratosthenes();

    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;

        cout << Goldbach(n) << '\n';
    }
}

void Eratosthenes(int upper) {
    prime_num.resize(upper + 1, true);
    prime_num[0] = false; prime_num[1] = false;

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

int Goldbach(int n) {
    int ans = 0;

    for (int i = 2; i <= n / 2; i++) {
        if (!prime_num[i])
            continue;

        if (prime_num[n - i]) {
            ans++;
        }
    }

    return ans;
}