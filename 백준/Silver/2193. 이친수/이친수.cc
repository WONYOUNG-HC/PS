#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n; cin >> n;

    vector<long long> end0(n + 1);
    vector<long long> end1(n + 1);
    end1[1] = 1; end0[2] = 1;

    for (int i = 2; i <= n; i++) {
        end0[i] = end0[i - 1] + end1[i - 1];
        end1[i] = end0[i - 1];
    }

    cout << end0[n] + end1[n];
}