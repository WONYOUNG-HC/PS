#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

vector<int> nums;
vector<int> prime_num;
vector<map<int, int>> fact;
map<int, int> all_prime;

void Eratosthenes(int upper = 1000000);
void Factorization(int n);
pair<int, int> Scoring(int n);

int main() {
    int n;
    cin >> n;

    nums.resize(n);
    for (int i=0; i<n; i++)
        cin >> nums[i];

    Eratosthenes();
    Factorization(n);
    pair<int, int> ans = Scoring(n);

    cout << ans.first << ' ' << ans.second;
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

    for (int i=2; i<=upper; i++) {
        if (sieve[i])
            prime_num.push_back(i);
    }
}

void Factorization(int n) {
    fact.resize(n);

    for (int i=0; i<n; i++) {
        int j = 0;
        while (nums[i] != 1) {
            if (nums[i] % prime_num[j] == 0) {
                nums[i] /= prime_num[j];

                pair<map<int, int>::iterator, bool> pr;
                pr = fact[i].insert({prime_num[j], 1});
                if (!pr.second) fact[i][prime_num[j]]++;

                pr = all_prime.insert({prime_num[j], 1});
                if (!pr.second) all_prime[prime_num[j]]++;
            }
            else {
                j++;
            }
        }
    }
}

pair<int, int> Scoring(int n) {
    vector<pair<int, int>> result;

    for (pair<const int, int>& pr : all_prime) {
        int k = pr.second / n;

        if (k > 0)
            result.emplace_back(pr.first, k);
    }

    int score = 1;
    for (pair<int, int>& pr : result)
        score *= (int)pow(pr.first, pr.second);

    int cnt = 0;
    for (int i=0; i<n; i++) {
        for (pair<int, int>& pr : result) {
            if (pr.second > fact[i][pr.first])
                cnt += pr.second - fact[i][pr.first];
        }
    }

    return {score, cnt};
}