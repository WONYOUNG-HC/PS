#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> solution(n);
    for (int i=0; i<n; i++)
        cin >> solution[i];

    int value = 2100000000, left = 0, right = n-1;
    int i = left; int j = right;
    while (i != j) {
        int sum = solution[i] + solution[j];

        if (value > abs(sum)) {
            value = abs(sum);
            left = i;
            right = j;
        }

        if (sum > 0) j--;
        else if (sum < 0) i++;
        else break;
    }

    cout << solution[left] << ' ' << solution[right];
}