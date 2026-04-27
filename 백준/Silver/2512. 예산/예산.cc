#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Divide(vector<int>& city, int m);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> city(n);
    for (int i=0; i<n; i++)
        cin >> city[i];

    int m;
    cin >> m;

    cout << Divide(city, m);
}

bool Decision(vector<int>& city, int m, int mid) {
    int sum = 0;
    for (int budget : city) {
        if (mid > budget)
            sum += budget;
        else
            sum += mid;

        if (sum > m)
            return false;
    }

    return true;
}

int Divide(vector<int>& city, int m) {
    int left = 0, mid;
    int right = *max_element(city.begin(), city.end());

    while (left < right) {
        mid = (left + right + 1) / 2;

        if (Decision(city, m, mid)) {
            left = mid;
        }
        else {
            right = mid - 1;
        }
    }

    return left;
}