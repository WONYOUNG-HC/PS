#include <iostream>
#include <vector>

using namespace std;

vector<string> Stars(int n);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> ans = Stars(n);

    for (int i=0; i<n; i++) {
        for (int j=i; j<n-1; j++)
            cout << " ";

        cout << ans[i];

        for (int j=i; j<n-1; j++)
            cout << " ";
        cout << "\n";
    }

    return 0;
}

vector<string> Stars(int n) {
    vector<string> ret;

    if (n == 3) {
        ret.emplace_back("*");
        ret.emplace_back("* *");
        ret.emplace_back("*****");
        return ret;
    }

    vector<string> str = Stars(n / 2);
    for (int i=0; i<n/2; i++) {
        str.emplace_back(str[i]);

        for (int j=i*2; j<n-1; j++)
            str.back() += " ";

        str.back() += str[i];
    }

    return str;
}