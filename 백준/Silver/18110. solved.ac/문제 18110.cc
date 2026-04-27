#include <iostream>
#include <set>
#include <numeric>
#include <cmath>

using namespace std;

int n;
multiset<int> ms;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        ms.insert(c);
    }
    int ex = round(n * 0.15);
    cout << (n == 0 ? 0 : round(accumulate(next(ms.begin(), ex), prev(ms.end(), ex), 0) / (n - ex * 2.0)));
}