#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> prime_nums;

void Eratosthenes(int upper);

int main() {
    int n;
    cin >> n;

    Eratosthenes(n);

    int sum = 0, cnt = 0;
    int i = 0, j = 0;
    while (i < (int)prime_nums.size() || sum >= n) {
        if (sum < n) sum += prime_nums[i++];
        else if (sum > n) sum -= prime_nums[j++];
        else {
            cnt++;
            sum -= prime_nums[j++];
        }
    }

    cout << cnt;
}

void Eratosthenes(int upper) {
    vector<bool> sieve(upper+1, true);

    for (int i=2; i<=sqrt(upper); i++) {
        if (!sieve[i])
            continue;

        int j = i + i;
        while (j <= upper) {
            sieve[j] = false;
            j += i;
        }
    }

    for (int i=2; i<=upper; i++)
        if (sieve[i]) prime_nums.push_back(i);
}