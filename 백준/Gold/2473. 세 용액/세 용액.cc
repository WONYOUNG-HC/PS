#include <iostream>
#include <algorithm>

using namespace std;

int solution[5005];

void ThreeSolution(int n);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    for (int i = 0; i < n; i++)
        cin >> solution[i];

    ThreeSolution(n);
}

long long absLong(long long num) {
    return num > 0 ? num : -num;
}

void ThreeSolution(int n) {
    sort(solution, solution + n);

    int ans[3];
    long long value = 5e9;

    for (int k = 0; k < n; k++) {
        int s1 = solution[k];

        int i = (k == 0 ? 1 : 0);
        int j = (k == n - 1 ? n - 2 : n - 1);
        while (i < j) {
            int s2 = solution[i];
            int s3 = solution[j];
            long long sum = (long long)s1 + s2 + s3;

            if (value > absLong(sum)) {
                value = absLong(sum);
                ans[0] = s1;
                ans[1] = s2;
                ans[2] = s3;
            }

            if (sum < 0) {
                i++;
                if (i == k) i++;
            }
            else if (sum > 0) {
                j--;
                if (j == k) j--;
            }
            else {
                break;
            }
        }
    }

    sort(ans, ans + 3);
    for (int a : ans)
        cout << a << ' ';
}