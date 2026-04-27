#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

long long ManageMoney(vector<int>& money, int m);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> money(n);
    for (int i=0; i<n; i++)
        cin >> money[i];

    cout << ManageMoney(money, m);
}

bool Decision(vector<int>& money, long long mid, int m) {
    long long k = mid;
    m--;
    for (int day : money) {
        if (k < day) {
            k = mid;
            m--;
        }
        k -= day;

        if (k < 0 || m < 0)
            return false;
    }

    return true;
}

long long ManageMoney(vector<int>& money, int m) {
    long long left = 0, mid = -1;
    long long right = accumulate(money.begin(), money.end(), 0);

    while (left <= right) {
        mid = (left + right) / 2;
        if (Decision(money, mid, m)) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return left;
}