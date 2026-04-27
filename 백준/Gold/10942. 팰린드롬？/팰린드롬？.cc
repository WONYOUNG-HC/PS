#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<bool>> palindrome;

void CheckPalindrome(vector<int>& nums, int n);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vector<int> nums(n+1);
    for (int i=1; i<=n; i++)
        cin >> nums[i];

    CheckPalindrome(nums, n);

    int m; cin >> m;
    for (int i=0; i<m; i++) {
        int s, e;
        cin >> s >> e;
        cout << palindrome[s][e] << '\n';
    }

    return 0;
}

void CheckPalindrome(vector<int>& nums, int n) {
    palindrome.resize(n+1, vector<bool>(n+1));
    for (int i=1; i<=n; i++) {
        palindrome[i][i] = true;

        if (i != n && nums[i] == nums[i+1])
            palindrome[i][i+1] = true;
    }

    for (int diag = 2; diag <= n; diag++) {
        for (int i=1; i + diag <= n; i++) {
            int j = i + diag;

            if (nums[i] == nums[j] && palindrome[i+1][j-1])
                palindrome[i][j] = true;
        }
    }
}