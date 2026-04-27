#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int Eratosthenes(long long start, long long end);

int main() {
    long long start, end;
    scanf("%lld %lld", &start, &end);

    printf("%d", Eratosthenes(start, end));
}

int Eratosthenes(long long start, long long end) {
    int root = (int)(sqrt(end));
    int diff = (int)(end - start);
    vector<bool> sieve(root + 1, true);
    vector<bool> not_square(diff + 1, true);

    for (int i = 2; i <= root; i++) {
        if (!sieve[i])
            continue;

        long long square = (long long)i * i;

        long long j = square;
        while (j <= root) {
            sieve[j] = false;
            j += i;
        }

        long long quotient = start / square;
        long long k = quotient * square;
        if (start % square != 0) k += square;
        while (k <= end) {
            not_square[k - start] = false;
            k += square;
        }
    }

    int ans = 0;
    for (bool b : not_square)
        if (b) ans++;

    return ans;
}
